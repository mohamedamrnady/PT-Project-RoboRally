#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"

class RebootandRepair : public Action
{
public:
	RebootandRepair(ApplicationManager *pApp);
	virtual void ReadActionParameters(); // Reads action parameters
	virtual void Execute();				 // Executes the action to create the play mode toolbar
	virtual ~RebootandRepair();
};
