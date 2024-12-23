#pragma once
#include "GameObject.h"
#include "Player.h"

class RotatingGear : public GameObject
{
	bool isClockWise; // if it is true then direction is clockwise, if it is false then direction is anticlockwise
public:
	RotatingGear(const CellPosition &gearposition, bool clockwise); // A constructor for initialization
	virtual void Draw(Output *pOut) const;							// Draws a rotating gear in a selected cell
	virtual void Apply(Grid *pGrid, Player *pPlayer);				// Applys the effect of the flag
	bool GetisClockWise() const;									// Getter for the direction
	virtual ~RotatingGear();
};
