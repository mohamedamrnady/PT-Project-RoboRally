#pragma once
#include "Action.h"
#include "GameObject.h"
class PasteAction : public Action
{
private:
	CellPosition cellpasted;

public:
	PasteAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
