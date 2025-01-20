#pragma once
#include <fstream>
#include "GameObject.h"
class WaterPit : public GameObject
{
public:
	WaterPit(const CellPosition &waterPitPosition); // A constructor for initialization
	virtual void Draw(Output *pOut) const;			// Draws a water pit in the cell

	virtual void Apply(Grid *pGrid, Player *pPlayer); // Applys the effect of the waterPit by killing the robot instantly and ending the game

	virtual void Save(ofstream &OutFile, int t); // prints cell postion

	virtual int GetObjType();

	virtual void Load(ifstream &Infile);
	virtual GameObject *clone() const;

	virtual ~WaterPit();
};
