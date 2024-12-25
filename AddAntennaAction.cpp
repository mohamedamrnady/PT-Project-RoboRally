#include "AddAntennaAction.h"
#include "Antenna.h"

AddAntennaAction::AddAntennaAction(ApplicationManager *pApp) : Action(pApp)
{
}

void AddAntennaAction::ReadActionParameters()
{
    Input *pIn = pManager->GetGrid()->GetInput();
    Output *pOut = pManager->GetGrid()->GetOutput();

    pOut->PrintMessage("New Antenna: Click on its Cell ...");
    Pos = pIn->GetCellClicked();

    if (!Pos.IsValidCell())
    {
        pOut->PrintMessage("Invalid parameters! Please try again.");
        return;
    }
    pOut->ClearStatusBar();
}

void AddAntennaAction::Execute()
{
    Grid *pGrid = pManager->GetGrid();

    if (pGrid->GetNumAntennas() > 0)
    {
        pGrid->PrintErrorMessage("Error: Game already has an antenna!");
        return;
    }
    ReadActionParameters();

    Antenna *pAntenna = new Antenna(Pos);

   Output *pOut = pGrid->GetOutput();

    bool added = pGrid->AddObjectToCell(pAntenna);

    if (!added)
    {
       pOut->PrintMessage("Error: Cell already has an object!");
    }
    else
    {
        pGrid->SetNumAntennas(1);
    }
}

AddAntennaAction::~AddAntennaAction()
{
}