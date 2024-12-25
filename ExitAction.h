#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Flag.h"
#include "Cell.h"
class ExitAction : public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	bool GameEnded;

public:
	ExitAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); // Reads action parameters

	virtual void Execute();

	~ExitAction();
};
