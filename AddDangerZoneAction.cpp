#include "AddDangerZoneAction.h"

AddDangerZoneAction::AddDangerZoneAction(ApplicationManager *pApp) : Action(pApp)
{
}

void AddDangerZoneAction::ReadActionParameters()
{
	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Input *pIn = pManager->GetGrid()->GetInput();
	Output *pOut = pManager->GetGrid()->GetOutput();

	pOut->PrintMessage("New Object: Click on its Cell ...");
	Pos = pIn->GetCellClicked();

	if (!Pos.IsValidCell())
	{
		pOut->PrintMessage("Invalid parameters! Please try again.");
		return;
	}
	pOut->ClearStatusBar();
}

void AddDangerZoneAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first
	// and hence initializes its data members
	ReadActionParameters();
	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	DangerZone *pZone = new DangerZone(Pos);

	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();

	bool added = pGrid->AddObjectToCell(pZone);

	if (!added)
	{
		pOut->PrintMessage("Error: Cell already has an object!");
	}
	else
		pGrid->SetnumDangerZones((pGrid->GetnumDangerZones()) + 1);
}

AddDangerZoneAction::~AddDangerZoneAction()
{
}
