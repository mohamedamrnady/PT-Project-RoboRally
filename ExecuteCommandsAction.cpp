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

    Output *pOut = pGrid->GetOutput();
    pOut->PrintMessage("Shooting phase: click to start ... ");

    Direction Direction1 = CurrentPlayer->getDirection();
    CellPosition position1 = CurrentPlayer->GetCell()->GetCellPosition();

    pGrid->AdvanceCurrentPlayer();
    CurrentPlayer = pGrid->GetCurrentPlayer(); // no points to the other player

    Direction Direction2 = CurrentPlayer->getDirection();
    CellPosition position2 = CurrentPlayer->GetCell()->GetCellPosition();

    pGrid->AdvanceCurrentPlayer();
    CurrentPlayer = pGrid->GetCurrentPlayer(); // return to the player who it is his turn

    bool CanShoot = false; // get the possibility to shoot

    // Now compare them in positio
    if (position1.HCell() == position2.HCell())
    {
        if (position1.VCell() > position2.VCell())
        {
            if (Direction1 == UP)
                CanShoot = true;
        }
        else if (Direction1 == DOWN)
            CanShoot = true;
    }
    else if (position1.VCell() == position2.VCell())
    {
        if (position1.HCell() > position2.HCell())
        {
            if (Direction1 == LEFT)
                CanShoot = true;
        }
        else if (Direction1 == RIGHT)
            CanShoot = true;
    }

    // get info of current player
    string laserType = CurrentPlayer->getLaserType();

    if (CanShoot)
    {
        pGrid->AdvanceCurrentPlayer();
        Player *OtherPlayer = pGrid->GetCurrentPlayer();
        if (laserType == "Standard")
            OtherPlayer->SetHealth(OtherPlayer->GetHealth() - 1, pGrid);
        else if (laserType == "double")
        {
            OtherPlayer->SetHealth(OtherPlayer->GetHealth() - 2, pGrid);
        }
        else
            pOut->PrintMessage("Invalid laser type");
    }
    else
    {
        pGrid->PrintErrorMessage("Can't shoot!");
    }
    pGrid->AdvanceCurrentPlayer();
}

ExecuteCommandsAction::~ExecuteCommandsAction()
{
}