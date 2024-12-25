#pragma once
#include <fstream>
#include "GameObject.h"
class Workshop : public GameObject
{
	CellPosition workshoppos;

public:
	Workshop(const CellPosition &workshopPosition);
	virtual void Draw(Output *pOut) const; // Draws workshop

	virtual void Apply(Grid *pGrid, Player *pPlayer); // Applys the effect of the workshop

	virtual void Save(ofstream& OutFile, int t); //prints cell postion

	virtual int GetObjType();
	virtual void Load(ifstream& Infile);
	virtual GameObject* clone() const;


	~Workshop();
};
