#include "CreatePlayModeToolBarAction.h"

CreatePlayModeToolBarAction::CreatePlayModeToolBarAction(ApplicationManager *pApp) : Action(pApp)
{
}

void CreatePlayModeToolBarAction::ReadActionParameters()
{
    // No parameters to read for this action
}

void CreatePlayModeToolBarAction::Execute()
{
    // Get a Pointer to the Output Interface
    Output *pOut = pManager->GetGrid()->GetOutput();

    // Create the Play Mode Toolbar
    pOut->CreatePlayModeToolBar();
}

CreatePlayModeToolBarAction::~CreatePlayModeToolBarAction()
{
}