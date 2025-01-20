#pragma once
#include <fstream>
#include "GameObject.h"
class Flag : public GameObject
{
public:
	Flag(const CellPosition &flagposition);			  // A constructor for initialization
	virtual void Draw(Output *pOut) const;			  // Draws a flag in a selected cell
	virtual void Apply(Grid *pGrid, Player *pPlayer); // Applys the effect of the flag

	virtual void Save(ofstream &OutFile, int t); // cell postion
	virtual int GetObjType();
	virtual void Load(ifstream &Infile);
	virtual GameObject *clone() const;

	virtual ~Flag(); // Virtual destructor
};