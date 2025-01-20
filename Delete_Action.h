#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
class Delete_Action : public Action
{
	CellPosition selectedCell;
	Grid *gridptr;

public:
	Delete_Action(ApplicationManager *pApp);

	// Reads rectangle parameters
	virtual void ReadActionParameters();

	// Add rectangle to the ApplicationManager
	virtual void Execute();
};
