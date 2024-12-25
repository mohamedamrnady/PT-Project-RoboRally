#include "CreateDesignModeToolBarAction.h"

CreateDesignModeToolBarAction::CreateDesignModeToolBarAction(ApplicationManager *pApp) : Action(pApp)
{
}

void CreateDesignModeToolBarAction::ReadActionParameters()
{
    // No parameters to read for this action
}

void CreateDesignModeToolBarAction::Execute()
{
    // Get a Pointer to the Output Interface
    Output *pOut = pManager->GetGrid()->GetOutput();

    // Create the Design Mode Toolbar
    pOut->CreateDesignModeToolBar();
}

CreateDesignModeToolBarAction::~CreateDesignModeToolBarAction()
{
}