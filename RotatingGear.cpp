#include "RotatingGear.h"

RotatingGear::RotatingGear(const CellPosition &gearposition, bool clockwise) : GameObject(gearposition)
{
	isClockWise = clockwise;
	gearpos = gearposition;
}

void RotatingGear::Draw(Output *pOut) const
{
	pOut->DrawRotatingGear(position, isClockWise);
}

void RotatingGear::Apply(Grid *pGrid, Player *pPlayer)
{

	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message and change the message according to direction of rotation "You have reached a rotating gear, you will rotate (clockwise/ anti-clockwise) Click to continue ..." and wait mouse click
	// 2- Apply the roating gear's effect by rotating the player according to the direction
}
bool RotatingGear::GetisClockWise() const
{
	return isClockWise;
}


void RotatingGear::Save(ofstream& OutFile, int t) {
	if (t == rotating_gear) {
		OutFile << gearpos.GetCellNum() << " ";
		if (isClockWise)
			OutFile << 1 << endl;
		else
			OutFile << 0 << endl;
	}
}

int RotatingGear::GetObjType() {

	return rotating_gear;
}


void RotatingGear::Load(ifstream& Infile) {
	int cellnum, clockwise;
	Infile >> cellnum;
	gearpos.SetCellNum(cellnum);
	position.SetCellNum(cellnum);
	Infile >> clockwise;
	if (clockwise == 1)
		isClockWise = true;
	else
		isClockWise =false;
}

GameObject* RotatingGear::clone() const{
	return new RotatingGear(*this);
}


RotatingGear::~RotatingGear()
{
}
