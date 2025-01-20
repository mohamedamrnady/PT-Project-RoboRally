#pragma once
#include "Action.h"
#include "GameObject.h"

class CutAction : public Action
{
	CellPosition cellselected;

public:
	CutAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	// Executes "Cut"
	virtual void Execute();
};
