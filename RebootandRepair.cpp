#include "RebootandRepair.h"

RebootandRepair::RebootandRepair(ApplicationManager *pApp) : Action(pApp)
{
}

void RebootandRepair::ReadActionParameters()
{
}

void RebootandRepair::Execute()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();
    Player *pPlayer = pGrid->GetCurrentPlayer();
    pOut->PrintMessage("Reboot and Repair: Click to continue ...");
    pIn->GetCellClicked();
    pPlayer->SetHealth(pPlayer->GetHealth() + 2, pGrid);
    pOut->ClearStatusBar();
    pGrid->AdvanceCurrentPlayer();
}

RebootandRepair::~RebootandRepair()
{
}