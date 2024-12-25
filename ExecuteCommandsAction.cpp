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
    if (pGrid->GetEndGame())
    {
        if (CurrentPlayer->GetHealth() == 0)
            pGrid->GetOutput()->PrintMessage("Player " + to_string(CurrentPlayer->GetPlayerNum()) + " has lost the game, click to continue");
        else
        {
            pGrid->GetOutput()->PrintMessage("Player " + to_string(CurrentPlayer->GetPlayerNum()) + " has won the game, click to continue");
        }
        return;
    }

    CurrentPlayer->Move(pGrid, CurrentPlayer->GetSavedCommands());
    pGrid->AdvanceCurrentPlayer();
    if (pGrid->GetCurrentPlayer()->GetIsHacked())
    {
        pGrid->GetOutput()->PrintMessage("Player " + to_string(pGrid->GetCurrentPlayer()->GetPlayerNum()) + " is hacked and can't play this round");
        pGrid->GetCurrentPlayer()->SetIsHacked(false);
        pGrid->AdvanceCurrentPlayer();
    }
}

ExecuteCommandsAction::~ExecuteCommandsAction()
{
}