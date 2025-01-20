#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include <fstream>

class SaveAction : public Action
{

private:
	string inputstring;
	Grid *gridptr;

public:
	SaveAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
