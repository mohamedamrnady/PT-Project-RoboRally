//#include "DangerZone.h"
//#include "Player.h"
//
//DangerZone::DangerZone(const CellPosition &dangerZonePosition) : GameObject(dangerZonePosition)
//{
//}
//
//void DangerZone::Draw(Output *pOut) const
//{
//	pOut->DrawDangerZone(position);
//}
//
//void DangerZone::Apply(Grid *pGrid, Player *pPlayer)
//{
//	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below
//
//	// == Here are some guideline steps (numbered below) to implement this function ==
//
//	// 1- Print a message "You have reached a danger zone. Click to continue ..." and wait mouse click
//	pGrid->PrintErrorMessage("You have reached a danger zone. Click to continue ...");
//
//	// 2- Apply the danger zone's effect by reducing the health of the player by 1
//	pPlayer->SetHealth(pPlayer->GetHealth() - 1);
//
//	// 3- Update the players info which is displayed (check Grid class and decide which function to use)
//	pGrid->UpdateInterface();
//}
//
//DangerZone::~DangerZone()
//{
//}

#include "DangerZone.h"



DangerZone::DangerZone(const CellPosition& dangerZonePosition) : GameObject(dangerZonePosition)
{
	dgpos = dangerZonePosition;
}

void DangerZone::Draw(Output* pOut) const
{
	pOut->DrawDangerZone(position);
}

void DangerZone::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a danger zone. Click to continue ..." and wait mouse click

	// 2- Apply the danger zone's effect by reducing the health of the player by 1 
	// 3- Update the players info which is displayed (check Grid class and decide which function to use)

}

void DangerZone::Save(ofstream& OutFile, int t) {
	if(t==danger_zone)
	OutFile << dgpos.GetCellNum() << endl;
}

int DangerZone::GetObjType() {
	return danger_zone;
}

void DangerZone::Load(ifstream& Infile) {
	int cellnum;
	Infile >> cellnum;
	dgpos.SetCellNum(cellnum);
	position.SetCellNum(cellnum);
}

GameObject* DangerZone::clone() const {
	return new DangerZone(*this);
}
DangerZone::~DangerZone()
{
}
