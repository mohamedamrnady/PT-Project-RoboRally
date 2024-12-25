#pragma once
#include "GameObject.h"

class BeltEnd : public GameObject
{
public:
	BeltEnd(const CellPosition &beltEndPosition); // A constructor for initialization
	virtual void Draw(Output *pOut) const;		  // Draws a belt end in the cell

	virtual void Apply(Grid *pGrid, Player *pPlayer); // Applys the effect of the belt end

	virtual ~BeltEnd();
};
