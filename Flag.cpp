#include "Flag.h"
Flag::Flag(const CellPosition &flagposition) : GameObject(flagposition)
{
}

void Flag::Draw(Output *pOut) const
{
	pOut->DrawFlag(position);
}

void Flag::Apply(Grid *pGrid, Player *pPlayer)
{

	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a flag. Click to continue ..." and wait mouse click
	Output *pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a flag. Click to continue ...");

	// 2- Apply the flag's effect by ending the game
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->SetEndGame(true);
}
void Flag::Save(ofstream &OutFile, int t)
{
	if (t == flag)
	{
		OutFile << position.GetCellNum() << endl;
	}
}

int Flag::GetObjType()
{
	return flag;
}

void Flag::Load(ifstream &Infile)
{
	int cellnum;
	Infile >> cellnum;
	position.SetCellNum(cellnum);
}
GameObject *Flag::clone() const
{
	return new Flag(*this);
}

Flag::~Flag()
{
}