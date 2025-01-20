#include "AddWorkshopAction.h"

AddWorkshopAction::AddWorkshopAction(ApplicationManager *pApp) : Action(pApp)
{
}

void AddWorkshopAction::ReadActionParameters()
{
    Input *pIn = pManager->GetGrid()->GetInput();
    Output *pOut = pManager->GetGrid()->GetOutput();

    pOut->PrintMessage("New Workshop: Click on its Cell ...");
    Pos = pIn->GetCellClicked();

    if (!Pos.IsValidCell())
    {
        pOut->PrintMessage("Invalid parameters! Please try again.");
        return;
    }
    pOut->ClearStatusBar();
}

void AddWorkshopAction::Execute()
{
    ReadActionParameters();

    Workshop *pWorkshop = new Workshop(Pos);

    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();

    bool added = pGrid->AddObjectToCell(pWorkshop);

    if (!added)
    {
        pOut->PrintMessage("Error: Cell already has an object!");
    }
    else
        pGrid->SetnumWorkshops((pGrid->GetnumWorkshops()) + 1);
}

AddWorkshopAction::~AddWorkshopAction()
{
}