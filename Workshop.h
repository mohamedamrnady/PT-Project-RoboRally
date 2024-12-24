#pragma once
#include "GameObject.h"
#include "WorkshopItem.h"

class Workshop : public GameObject
{
private:
	WorkshopItem *workshopItems[MAX_ITEM_COUNT]; // Array of pointers to workshop items

public:
	Workshop(const CellPosition &workshopPosition);
	virtual void Draw(Output *pOut) const; // Draws workshop

	virtual void Apply(Grid *pGrid, Player *pPlayer); // Applys the effect of the workshop

	~Workshop();
};
