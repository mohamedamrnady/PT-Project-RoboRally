#include "ExecuteCommandsAction.h"

ExecuteCommandsAction::ExecuteCommandsAction(ApplicationManager *pApp) : Action(pApp)
{
}

void ExecuteCommandsAction::ReadActionParameters()
{
    // No parameters to read for this action
}

void ExecuteCommandsAction::Execute()
{
    Grid *pGrid = pManager->GetGrid();
    Player *CurrentPlayer = pGrid->GetCurrentPlayer();

    CurrentPlayer->Move(pGrid, CurrentPlayer->GetSavedCommands());
    pGrid->AdvanceCurrentPlayer();
}

ExecuteCommandsAction::~ExecuteCommandsAction()
{
}