#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Belt.h"
#include "Player.h"
#include <iostream>

Grid::Grid(Input *pIn, Output *pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut);										  // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	numAntennas = 0;
	numWaterPits = 0;
	numFlag = 0;
	numDangerZones = 0;
	numBelts = 0;
	numWorkshops = 0;
	numRotatingGears = 0;

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}

// ========= Adding or Removing GameObjects to Cells =========

bool Grid::AddObjectToCell(GameObject *pNewObject) // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject *pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

// Note: You may need to change the return type of this function (Think)
bool Grid::RemoveObjectFromCell(const CellPosition &pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
		return true;
	}
	return false;
}

void Grid::UpdatePlayerCell(Player *player, const CellPosition &newPosition)
{
	// Clear the player's triangle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell *newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's triangle on the new cell position
	player->Draw(pOut);
}

// ========= Setters and Getters Functions =========

Input *Grid::GetInput() const
{
	return pIn;
}

Output *Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(GameObject *gameObject) // to be used in copy/cut
{
	delete Clipboard;
	Clipboard = gameObject;
}

GameObject *Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

void Grid::SetCurrentPlayer(int playerNum)
{
	currPlayerNumber = playerNum;
}

void Grid::SetNumAntennas(int numAntennas)
{
	this->numAntennas = numAntennas;
}

int Grid::GetNumAntennas() const
{
	return numAntennas;
}

int Grid::GetnumWaterPits() const
{
	return numWaterPits;
}

void Grid::SetnumWaterPits(int numWaterPits)
{
	this->numWaterPits = numWaterPits;
}

void Grid::SetNumFlag(int numFlag)
{
	this->numFlag = numFlag;
}

int Grid::GetNumFlag() const
{
	return numFlag;
}

void Grid::SetnumDangerZones(int numDangerZones)
{
	this->numDangerZones = numDangerZones;
}

int Grid::GetnumDangerZones() const
{
	return numDangerZones;
}

void Grid::SetnumBelts(int numBelts)
{
	this->numBelts = numBelts;
}

int Grid::GetnumBelts() const
{
	return numBelts;
}

void Grid::SetnumWorkshops(int numWorkshops)
{
	this->numWorkshops = numWorkshops;
}

int Grid::GetnumWorkshops() const
{
	return numWorkshops;
}

void Grid::SetnumRotatingGears(int numRotatingGears)
{
	this->numRotatingGears = numRotatingGears;
}

int Grid::GetnumRotatingGears() const
{
	return numRotatingGears;
}

// ========= Other Getters =========

Player *Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Belt *Grid::GetNextBelt(const CellPosition &position)
{

	int startH = position.HCell();				// represents the start hCell in the current row to search for the belt in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{

			/// TODO: Check if CellList[i][j] has a belt, if yes return it
			if (CellList[i][j]->HasBelt())
			{
				Belt *ptrBelt = dynamic_cast<Belt *>(CellList[i][j]->GetGameObject());
				return (ptrBelt);
			}
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

// ========= User Interface Functions =========

void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without waterpits or dangerzone
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrWaterPitOrDangerZone(pOut);
			}
		}

		// 2- Draw other game objects(excluding waterpit and dangerzone)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawGameObject(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1)					  // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cgame objects do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Grid::DeleteGameObj(const CellPosition &selected_cell)
{

	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			if (CellList[i][j] != nullptr)
			{
				if ((CellList[i][j]->GetCellPosition()).GetCellNum() == selected_cell.GetCellNum())
				{
					int type = CellList[i][j]->DeleteGameObj(selected_cell);
					switch (type)
					{
					case flag:
						if (numFlag > 0)
							numFlag--;
						break;
					case water_pit:
						if (numWaterPits > 0)
							numWaterPits--;
						break;
					case danger_zone:
						if (numDangerZones > 0)
							numDangerZones--;
						break;
					case belt:
						if (numBelts > 0)
							numBelts--;
						break;
					case workshop:
						if (numWorkshops > 0)
							numWorkshops--;
						break;
					case antenna:
						if (numAntennas > 0)
							numAntennas--;
						break;
					case rotating_gear:
						if (numRotatingGears > 0)
							numRotatingGears--;
						break;
					}
					return;
				}
			}
		}
	}
}

void Grid::SaveAll(ofstream &outfile, int type)
{ // saves all objects of a certain type
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j] != nullptr)
			{
				GameObject *gobj = CellList[i][j]->GetGameObject();
				if (gobj != nullptr)
				{
					if (gobj->GetObjType() == type) // to save all objects of a certain type
						CellList[i][j]->GetGameObject()->Save(outfile, type);
				}
			}
		}
	}
}

GameObject *Grid::GetGameObjectfromCellPosition(const CellPosition &selected_cell)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if ((CellList[i][j]->GetCellPosition()).GetCellNum() == selected_cell.GetCellNum())
			{
				return CellList[i][j]->GetGameObject();
			}
		}
	}

	return nullptr;
}

void Grid::DeallocateClipboard()
{
	delete Clipboard;
}

Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}