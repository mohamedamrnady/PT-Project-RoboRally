#include "AddFlagAction.h"

AddFlagAction::AddFlagAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddFlagAction::ReadActionParameters()
{

	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Input *pIn = pManager->GetGrid()->GetInput();
	Output *pOut = pManager->GetGrid()->GetOutput();

	// 2- Read the flagPos
	pOut->PrintMessage("New Object: Click on its Cell ...");
	flagPos = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters
	if (flagPos.IsValidCell())
	{ //
		pOut->PrintMessage("Flag have a valid position");
		pIn->GetCellClicked();

		pOut->ClearStatusBar();
		return;
	}
	// 5- Clear status bar
	pOut->PrintMessage("Not valid position for flag");
	pOut->ClearStatusBar();
}

void AddFlagAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first
	// and hence initializes its data members
	ReadActionParameters();
	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a flag object
	Flag *pFlag = new Flag(flagPos);
	Output *pOut = pManager->GetGrid()->GetOutput();
	// 2-get a pointer to the Grid from the ApplicationManager
	Grid *pGrid = pManager->GetGrid();
	if (pGrid->GetNumFlag() > 0)
	{
		pGrid->PrintErrorMessage("Error: Game already has a Flag!");
		return;
	}

	// 3-Add the flag object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pFlag);
	// 4-Check if the flag was added and print an errror message if flag couldn't be added
	if (!added)
	{
		pOut->PrintMessage("Flag not added");
		pOut->ClearStatusBar();
	}
	else
	{
		pGrid->SetNumFlag(1);
	}
}

AddFlagAction::~AddFlagAction()
{
}