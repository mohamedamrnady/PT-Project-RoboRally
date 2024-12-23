#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"

class ExecuteCommandsAction : public Action
{
public:
    ExecuteCommandsAction(ApplicationManager *pApp);
    virtual void ReadActionParameters(); // Reads action parameters
    virtual void Execute();              // Executes the action to create the design mode toolbar
    virtual ~ExecuteCommandsAction();
};