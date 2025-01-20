#pragma once
#include <fstream>
#include "GameObject.h"
#include "WorkshopItem.h"

class Workshop : public GameObject
{
private:
	WorkshopItem *workshopItems[WORKSHOP_ITEMS_COUNT]; // Array of pointers to workshop items

public:
	Workshop(const CellPosition &workshopPosition);
	virtual void Draw(Output *pOut) const; // Draws workshop

	virtual void Apply(Grid *pGrid, Player *pPlayer);						// Applys the effect of the workshop
	void ExecuteItem(Grid *pGrid, Player *pPlayer, WorkshopItemTypes item); // Executes the item of the workshop

	virtual void Save(ofstream &OutFile, int t); // prints cell postion

	virtual int GetObjType();
	virtual void Load(ifstream &Infile);
	virtual GameObject *clone() const;

	~Workshop();
};
