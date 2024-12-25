#include "Player.h"

#include "GameObject.h"

Player::Player(Cell *pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT)
{
	this->pCell = pCell;

	// Make all the needed initialization or validations
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

void Player::SetHealth(int h)
{
	this->health = h;
	/// TODO: Do any needed validations
}

int Player::GetHealth()
{
	return this->health;
}

int Player::GetPlayerNum() const
{
	return playerNum;
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
	for (int i = 0; i < sizeof(moveCommands); i++)
	{
		// MOVE_FORWARD_ONE_STEP UP == MOVE_BACKWARD_ONE_STEP DOWN
		// Execute the command
		switch (moveCommands[i])
		{
		// Add cases for the new Command enum values
		case MOVE_FORWARD_ONE_STEP:
			switch (currDirection)
			{
			case UP:
				if (currentCellPos.VCell() > 0)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() - 1);
				}
				break;
			case DOWN:
				if (currentCellPos.VCell() < NumVerticalCells - 1)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() + 1);
				}
				break;
			case LEFT:
				if (currentCellPos.HCell() > 0)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() - 1);
				}
				break;
			case RIGHT:
				if (currentCellPos.HCell() < NumHorizontalCells - 1)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() + 1);
				}
				break;
			}
			break;

		case MOVE_BACKWARD_ONE_STEP:
			switch (currDirection)
			{
			case UP:
				if (currentCellPos.VCell() < NumVerticalCells - 1)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() + 1);
				}
				break;
			case DOWN:
				if (currentCellPos.VCell() > 0)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() - 1);
				}
				break;
			case LEFT:
				if (currentCellPos.HCell() < NumHorizontalCells - 1)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() + 1);
				}
				break;
			case RIGHT:
				if (currentCellPos.HCell() > 0)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() - 1);
				}
				break;
			}
			break;

		case MOVE_FORWARD_TWO_STEPS:
			switch (currDirection)
			{
			case UP:
				if (currentCellPos.VCell() > 1)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() - 2);
				}
				break;
			case DOWN:
				if (currentCellPos.VCell() < NumVerticalCells - 2)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() + 2);
				}
				break;
			case LEFT:
				if (currentCellPos.HCell() > 1)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() - 2);
				}
				break;
			case RIGHT:
				if (currentCellPos.HCell() < NumHorizontalCells - 2)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() + 2);
				}
				break;
			}
			break;

		case MOVE_BACKWARD_TWO_STEPS:
			switch (currDirection)
			{
			case UP:
				if (currentCellPos.VCell() < NumVerticalCells - 2)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() + 2);
				}
				break;
			case DOWN:
				if (currentCellPos.VCell() > 1)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() - 2);
				}
				break;
			case LEFT:
				if (currentCellPos.HCell() < NumHorizontalCells - 2)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() + 2);
				}
				break;
			case RIGHT:
				if (currentCellPos.HCell() > 1)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() - 2);
				}
				break;
			}
			break;

		case MOVE_FORWARD_THREE_STEPS:
			switch (currDirection)
			{
			case UP:
				if (currentCellPos.VCell() > 2)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() - 3);
				}
				break;
			case DOWN:
				if (currentCellPos.VCell() < NumVerticalCells - 3)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() + 3);
				}
				break;
			case LEFT:
				if (currentCellPos.HCell() > 2)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() - 3);
				}
				break;
			case RIGHT:
				if (currentCellPos.HCell() < NumHorizontalCells - 3)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() + 3);
				}
				break;
			}
			break;

		case MOVE_BACKWARD_THREE_STEPS:
			switch (currDirection)
			{
			case UP:
				if (currentCellPos.VCell() < NumVerticalCells - 3)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() + 3);
				}
				break;
			case DOWN:
				if (currentCellPos.VCell() > 2)
				{
					currentCellPos.SetVCell(currentCellPos.VCell() - 3);
				}
				break;
			case LEFT:
				if (currentCellPos.HCell() < NumHorizontalCells - 3)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() + 3);
				}
				break;
			case RIGHT:
				if (currentCellPos.HCell() > 2)
				{
					currentCellPos.SetHCell(currentCellPos.HCell() - 3);
				}
				break;
			}
			break;

		case ROTATE_CLOCKWISE:
			currDirection = static_cast<Direction>((currDirection + 1) % 4);
			break;

		case ROTATE_COUNTERCLOCKWISE:
			currDirection = static_cast<Direction>((currDirection + 3) % 4);
			break;
		}
		pGrid->UpdatePlayerCell(this, currentCellPos);

		pGrid->GetOutput()->PrintMessage("Click anywhere to execute the next command");
		pGrid->GetInput()->GetCellClicked();
	}
	pCell->GetGameObject()->Apply(pGrid, this);
}

void Player::AppendPlayerInfo(string &playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(currDirection) + ", ";
	playersInfo += to_string(health) + ")";
}