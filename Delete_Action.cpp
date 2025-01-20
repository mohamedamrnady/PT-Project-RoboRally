#include "Delete_Action.h"

Delete_Action::Delete_Action(ApplicationManager *pApp) : Action(pApp)
{
	gridptr = pApp->GetGrid();
}

void Delete_Action::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetGrid()->GetOutput();
	Input *pIn = pManager->GetGrid()->GetInput();
	pOut->PrintMessage("Select object you want to delete");
	selectedCell = pIn->GetCellClicked();
	pOut->PrintMessage("The selected object is deleted");
}
void Delete_Action::Execute()
{
	// This action needs to read some parameters first
	ReadActionParameters();
	gridptr->DeleteGameObj(selectedCell);
}
