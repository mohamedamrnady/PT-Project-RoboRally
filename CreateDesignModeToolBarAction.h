#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

class CreateDesignModeToolBarAction : public Action
{
public:
    CreateDesignModeToolBarAction(ApplicationManager *pApp);
    virtual void ReadActionParameters(); // Reads action parameters
    virtual void Execute();              // Executes the action to create the design mode toolbar
    virtual ~CreateDesignModeToolBarAction();
};