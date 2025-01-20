#include "AddRotatingGearAction.h"

AddRotatingGearAction::AddRotatingGearAction(ApplicationManager *pApp) : Action(pApp)
{
}

void AddRotatingGearAction::ReadActionParameters()
{
	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Input *pIn = pManager->GetGrid()->GetInput();
	Output *pOut = pManager->GetGrid()->GetOutput();

	// 2- Read the gearPos
	pOut->PrintMessage("New Rotating Gear: Click on its Cell ...");
	gearPos = pIn->GetCellClicked();

	// 3- Read whether the direction will be clockwise or not
	pOut->PrintMessage("Enter the direction (0 for counterclockwise, 1 for clockwise): ");
	int direction = pIn->GetInteger(pOut);

	// 4- Make the needed validations on the read parameters
	if (!gearPos.IsValidCell() || (direction != 0 && direction != 1))
	{
		pOut->PrintMessage("Invalid parameters! Please try again.");
		return;
	}
	clockwise = direction == 0 ? false : true;
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddRotatingGearAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first
	// and hence initializes its data members
	ReadActionParameters();
	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a rotating gear object
	RotatingGear *pGear = new RotatingGear(gearPos, clockwise);

	// 2-get a pointer to the Grid from the ApplicationManager
	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();

	// 3-Add the rotating object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pGear);

	// 4-Check if the rotating gear was added and print an error message if flag couldn't be added
	if (added)
	{
		pOut->PrintMessage("Rotating Gear added successfully");
		pGrid->SetnumRotatingGears((pGrid->GetnumRotatingGears()) + 1);
	}
	else
	{
		pOut->PrintMessage("Error: Cell already has an object!");
	}
}

AddRotatingGearAction::~AddRotatingGearAction()
{
}
