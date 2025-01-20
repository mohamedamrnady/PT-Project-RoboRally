#pragma once
#include "Action.h"
#include "GameObject.h"
class CopyAction : public Action
{
	CellPosition cellselected;

public:
	CopyAction(ApplicationManager *pApp);

	// static void copy(CFigure*& clipbrd, const CFigure* sourcefig);  //not sure el source hyeb2a constant pointer walla refrence lessa

	// till now maloosh ay m3na bas has to be implemented
	virtual void ReadActionParameters();

	// Executes "Copy"
	virtual void Execute();
};
