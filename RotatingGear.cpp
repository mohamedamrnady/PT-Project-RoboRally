#include "RotatingGear.h"

RotatingGear::RotatingGear(const CellPosition &gearposition, bool clockwise) : GameObject(gearposition)
{
	isClockWise = clockwise;
}

void RotatingGear::Draw(Output *pOut) const
{
	pOut->DrawRotatingGear(position, isClockWise);
}

void RotatingGear::Apply(Grid *pGrid, Player *pPlayer)
{

	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message and change the message according to direction of rotation "You have reached a rotating gear, you will rotate (clockwise  / anti-clockwise  ) Click to continue ..." and wait mouse click
	// 2- Apply the roating gear's effect by rotating the player according to the direction
	Output *pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	pPlayer->ClearDrawing(pOut);
	if (isClockWise)
	{
		pOut->PrintMessage("You have reached a rotating gear, you will rotate Clockwise Click to continue ...");
		pIn->GetCellClicked();

		pPlayer->setDirection(static_cast<Direction>((pPlayer->getDirection() + 1) % 4));
		pPlayer->Draw(pOut);
	}
	else
	{
		pOut->PrintMessage("You have reached a rotating gear, you will rotate Anti Clockwise Click to continue ...");
		pIn->GetCellClicked();

		pPlayer->setDirection(static_cast<Direction>((pPlayer->getDirection() - 1) % 4));
		pPlayer->Draw(pOut);
	}
}

bool RotatingGear::GetisClockWise() const
{
	return isClockWise;
}

RotatingGear::~RotatingGear()
{
}
