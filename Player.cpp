#include "Player.h"

#include "GameObject.h"

Player::Player(Cell *pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT)
{
	this->pCell = pCell;
	// Make all the needed initialization or validations
	laserType = "Standard";
	isHacked = false;
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

bool Player::SetHealth(int h)
{
	if (h > 0 && h <= 10)
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
/*
void Player::AddItem(WorkshopItem *item)
{
	// Check if the item is already purchased
	for (int i = 0; i < MAX_ITEM_COUNT; i++)
	{
		if (purchasedItems[i] == item)
		{
			return;
		}
	}
	// Add the item to the player's purchased items
	for (int i = 0; i < MAX_ITEM_COUNT; i++)
	{
		if (purchasedItems[i] == nullptr)
		{
			purchasedItems[i] = item;
			break;
		}
	}
}*/
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
	for (int i = 0; i < sizeof(moveCommands); i++)
	{
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
			break;
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

		currentCellPos.AddCellNum(steps, moveDirection);
		pGrid->UpdatePlayerCell(this, currentCellPos);

		pCell->GetGameObject()->Apply(pGrid, this);
		if (pGrid->GetEndGame())
		{
			return;
		}
		pGrid->GetOutput()->PrintMessage("Click anywhere to execute the next command");
		pGrid->GetInput()->GetCellClicked();
	}
}

void Player::AppendPlayerInfo(string &playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(";
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