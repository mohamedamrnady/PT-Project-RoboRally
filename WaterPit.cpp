#include "WaterPit.h"
#include "Player.h"

WaterPit::WaterPit(const CellPosition &waterPitPosition) : GameObject(waterPitPosition)
{
}

void WaterPit::Draw(Output *pOut) const
{
	pOut->DrawWaterPit(position);
}

void WaterPit::Apply(Grid *pGrid, Player *pPlayer)
{

	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message, make sure to edit this message according to which player wins "You drowned in a water pit. Player (0/1) wins !  Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You drowned in a water pit. Player " + std::to_string(pPlayer->GetPlayerNum()) + " lost! Click to continue ...");

	// 2- Apply the water pit's effect by setting the player's health which drowned to zero and ending the game
	pPlayer->SetHealth(0, pGrid);
	// 3- Update the players info which is displayed (check Grid class and decide which function to use)
	pGrid->UpdateInterface();
}

void WaterPit::Save(ofstream &OutFile, int t)
{
	if (t == water_pit)
		OutFile << position.GetCellNum() << endl;
}

int WaterPit::GetObjType()
{
	return water_pit;
}

void WaterPit::Load(ifstream &Infile)
{
	int cellnum;
	Infile >> cellnum;
	position.SetCellNum(cellnum);
}

GameObject *WaterPit::clone() const
{
	return new WaterPit(*this);
}

WaterPit::~WaterPit()
{
}
