#include "Workshop.h"

Workshop::Workshop(const CellPosition &workshopPosition) : GameObject(workshopPosition)
{
	workshoppos = workshopPosition;
}

void Workshop::Draw(Output *pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid *pGrid, Player *pPlayer)
{
}
void Workshop::Load(ifstream& Infile) {
	int cellnum;
	Infile >> cellnum;
	workshoppos.SetCellNum(cellnum);
	position.SetCellNum(cellnum);
}

int Workshop::GetObjType() {
	return workshop;
}


void Workshop::Save(ofstream& OutFile, int t) {
	if(t==workshop)
	OutFile << workshoppos.GetCellNum() << endl;
}

GameObject* Workshop::clone() const {
	return new Workshop(*this);
}



Workshop::~Workshop()
{
}
