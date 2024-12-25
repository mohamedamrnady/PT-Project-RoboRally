#include "AddWaterPitAction.h"

AddWaterPitAction::AddWaterPitAction(ApplicationManager *pApp) : Action(pApp)
{
}

void AddWaterPitAction::ReadActionParameters()
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

void AddWaterPitAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first
	// and hence initializes its data members
	ReadActionParameters();
	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	WaterPit *pZone = new WaterPit(Pos);

	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();

	bool added = pGrid->AddObjectToCell(pZone);

	if (!added)
	{
		pOut->PrintMessage("Error: Cell already has an object!");
	}
	else
		pGrid->SetnumWaterPits((pGrid->GetnumWaterPits()) + 1);
}

AddWaterPitAction::~AddWaterPitAction()
{
}
