#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"

class SelectCommandsAction : public Action
{
public:
    SelectCommandsAction(ApplicationManager *pApp);
    virtual void ReadActionParameters(); // Reads action parameters
    virtual void Execute();              // Executes the action to create the design mode toolbar
    virtual ~SelectCommandsAction();
};