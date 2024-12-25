#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

class CreatePlayModeToolBarAction : public Action
{
public:
	CreatePlayModeToolBarAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); // Reads action parameters
	virtual void Execute();				 // Executes the action to create the play mode toolbar
	virtual ~CreatePlayModeToolBarAction();
};
