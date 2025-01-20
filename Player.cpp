#include "Player.h"

#include "GameObject.h"

Player::Player(Cell *pCell, int playerNum) : stepCount(0), health(9), playerNum(playerNum), currDirection(RIGHT), NumOfSavedCommands(5)
{
	this->pCell = pCell;
	// Make all the needed initialization or validations
	laserType = "Standard";
	isHacked = false;
	purchasedItems = new WorkshopItemTypes[WORKSHOP_ITEMS_COUNT];
	for (int i = 0; i < WORKSHOP_ITEMS_COUNT; i++)
	{
		purchasedItems[i] = static_cast<WorkshopItemTypes>(-1); // Use -1 as a placeholder for uninitialized items
	}
}

// ====== Setters and Getters ======

void Player::SetCell(Cell *cell)
{
	pCell = cell;
}

Cell *Player::GetCell() const
{
	return pCell;
}

bool Player::SetHealth(int h, Grid *pGrid)
{
	if (h <= 0)
	{
		health = 0;
		pGrid->SetEndGame(true);
		return true;
	}
	else if (h > 0 && h <= 10)
	{
		this->health = h;
		return true;
	}
	else
		return false;
	/// TODO: Do any needed validations
}

int Player::GetHealth()
{
	return this->health;
}

Direction Player::getDirection()
{
	return currDirection;
}

void Player::setDirection(Direction dir)
{
	currDirection = dir;
}

void Player::SetSavedCommands(Command array[])
{
	SavedCommand = array;
}
Command *Player::GetSavedCommands()
{
	return SavedCommand;
}

int Player::GetPlayerNum() const
{
	return playerNum;
}
int Player::GetNumOfSavedCommands() const
{
	return NumOfSavedCommands;
}
void Player::SetNumOfSavedCommands(int num)
{
	if (num == 5 || num == 6)
		NumOfSavedCommands = num;
}

void Player::AddItem(WorkshopItemTypes item)
{
	// Check if the item is already purchased
	for (int i = 0; i < WORKSHOP_ITEMS_COUNT; i++)
	{
		if (purchasedItems[i] == item)
		{
			return;
		}
	}
	// Add the item to the player's purchased items
	for (int i = 0; i < WORKSHOP_ITEMS_COUNT; i++)
	{
		if (purchasedItems[i] == static_cast<WorkshopItemTypes>(-1)) // Check for uninitialized items
		{
			purchasedItems[i] = item;
			break;
		}
	}
}

WorkshopItemTypes *Player::GetItems() const
{

	return purchasedItems;
}

void Player::SetWorkshop(Workshop *workshop)
{
	pWorkshop = workshop;
}

Workshop *Player::GetWorkshop() const
{
	return pWorkshop;
}

void Player::UpgradeLaserType()
{
	laserType = "double";
};

string Player::getLaserType() const
{
	return laserType;
}

void Player::SetIsHacked(bool hacked)
{
	isHacked = hacked;
}

bool Player::GetIsHacked() const
{
	return isHacked;
}
// ====== Drawing Functions ======

void Player::Draw(Output *pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	/// TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor, currDirection);
}

void Player::ClearDrawing(Output *pOut) const
{
	/// TODO: Modify the cellColor to draw the correct cellColor (hint: if cell contains non-default cellColor)
	color cellColor = pCell->GetGameObject() ? pCell->HasDangerZone() ? UI.DangerZoneCellColor : pCell->HasWaterPit() ? UI.WaterPitsCellColor
																													  : UI.CellColor
											 : UI.CellColor;

	/// TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor, currDirection);
}

// ====== Game Functions ======

void Player::Move(Grid *pGrid, Command moveCommands[])
{

	/// TODO: Implement this function using the guidelines mentioned below

	// - If a player has 5 (could have less) saved moveCommands, the robot will execute the first saved command,
	//		then wait for a mouse click (display a message "Click anywhere to execute the next command").
	//		After executing all the 5 saved commands, the game object effect at the final destination cell will
	//		be applied.
	//
	// - Use the CellPosition class to help you calculate the destination cell using the current cell
	// - Use the Grid class to update pCell
	// - Don't forget to apply game objects at the final destination cell and check for game ending

	CellPosition currentCellPos = pCell->GetCellPosition();
	Output *pOut = pGrid->GetOutput();
	for (int i = 0; i < NumOfSavedCommands; i++) // sizeof(moveCommands)
	{
		bool isCommandRotating = false;
		// direction doesn't change if moving forward
		Direction moveDirection = currDirection;
		int steps = 0;
		// MOVE_FORWARD_ONE_STEP UP == MOVE_BACKWARD_ONE_STEP DOWN
		if (moveCommands[i] == MOVE_BACKWARD_ONE_STEP || moveCommands[i] == MOVE_BACKWARD_TWO_STEPS || moveCommands[i] == MOVE_BACKWARD_THREE_STEPS)
		{
			switch (currDirection)
			{
			case UP:
				moveDirection = DOWN;
				break;
			case DOWN:
				moveDirection = UP;
				break;
			case LEFT:
				moveDirection = RIGHT;
				break;
			case RIGHT:
				moveDirection = LEFT;
				break;
			}
		}
		// Get moving steps, ignoring direction
		if (moveCommands[i] == MOVE_FORWARD_ONE_STEP || moveCommands[i] == MOVE_BACKWARD_ONE_STEP)
		{
			steps = 1;
		}
		else if (moveCommands[i] == MOVE_FORWARD_TWO_STEPS || moveCommands[i] == MOVE_BACKWARD_TWO_STEPS)
		{
			steps = 2;
		}
		else if (moveCommands[i] == MOVE_FORWARD_THREE_STEPS || moveCommands[i] == MOVE_BACKWARD_THREE_STEPS)
		{
			steps = 3;
		}
		else if (moveCommands[i] == ROTATE_CLOCKWISE)
		{
			moveDirection = static_cast<Direction>((currDirection + 1) % 4);
			ClearDrawing(pOut);
			isCommandRotating = true;
		}
		else if (moveCommands[i] == ROTATE_COUNTERCLOCKWISE)
		{
			moveDirection = static_cast<Direction>((currDirection - 1) % 4);
			ClearDrawing(pOut);
			isCommandRotating = true;
		}
		if (isCommandRotating)
			setDirection(moveDirection);
		currentCellPos.AddCellNum(steps, moveDirection);
		pGrid->UpdatePlayerCell(this, currentCellPos);
		GameObject *pObj = pCell->GetGameObject();
		if (pObj && !isCommandRotating)
			pObj->Apply(pGrid, this);
		if (pGrid->GetEndGame())
		{
			return;
		}
		pOut->PrintMessage("Click anywhere to execute the next command " + to_string(i));
		pGrid->GetInput()->GetCellClicked();
	}

	pOut->PrintMessage("Executed All commands");
}

void Player::AppendPlayerInfo(string &playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(pCell->GetCellPosition().GetCellNum()) + ", ";
	switch (currDirection)
	{
	case UP:
		playersInfo += "UP, ";
		break;
	case DOWN:
		playersInfo += "DOWN, ";
		break;
	case LEFT:
		playersInfo += "LEFT, ";
		break;
	case RIGHT:
		playersInfo += "RIGHT, ";
		break;
	}
	playersInfo += to_string(health) + ")";
}
