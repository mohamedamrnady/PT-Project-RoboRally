#include "Belt.h"

Belt::Belt(const CellPosition &startCellPos, const CellPosition &endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	/// TODO: Do the needed validation
}
void Belt::Draw(Output *pOut) const
{
	pOut->DrawBelt(position, endCellPos);
}

void Belt::Apply(Grid *pGrid, Player *pPlayer)
{

	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a belt. Click to continue ..." and wait mouse click

	pGrid->GetOutput()->PrintMessage("You have reached a belt.Click to continue ...: ");
	pGrid->GetInput()->GetCellClicked();

	// 2- Apply the belt's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	//
	//	pGrid->AddObjectToCell();              // no need for this
	//	pGrid->RemoveObjectFromCell(position); // no need neither this
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}
CellPosition Belt::GetEndPosition() const
{
	return endCellPos;
}

void Belt::Save(ofstream &OutFile, int t)
{
	if (t == belt)
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}

int Belt::GetObjType()
{
	return belt;
}

void Belt::Load(ifstream &Infile)
{
	int startcellnum, endcellnum;
	Infile >> startcellnum;
	Infile >> endcellnum;
	position.SetCellNum(startcellnum);
	endCellPos.SetCellNum(endcellnum);
}

GameObject *Belt::clone() const
{
	return new Belt(*this);
}

Belt::~Belt()
{
}
