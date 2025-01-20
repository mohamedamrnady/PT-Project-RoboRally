#pragma once
#include "GameObject.h"
#include <fstream>

class BeltEnd : public GameObject
{
public:
	BeltEnd(const CellPosition &beltEndPosition); // A constructor for initialization
	virtual void Draw(Output *pOut) const;		  // Draws a belt end in the cell

	virtual void Apply(Grid *pGrid, Player *pPlayer); // Applys the effect of the belt end

	virtual ~BeltEnd();

	CellPosition GetEndPosition() const;		 // A getter for the endCellPos data member
	virtual void Save(ofstream &OutFile, int t); // prints number and cell postion
	virtual int GetObjType();
	virtual void Load(ifstream &Infile);
	virtual GameObject *clone() const;
};
