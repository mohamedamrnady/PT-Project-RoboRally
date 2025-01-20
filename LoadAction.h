#pragma once
#include "Action.h"
#include <fstream>

class LoadAction : public Action
{
	string inputstring;
	Grid *gridptr;

public:
	LoadAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};