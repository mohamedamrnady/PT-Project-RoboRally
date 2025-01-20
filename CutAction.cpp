#include "CutAction.h"
CutAction::CutAction(ApplicationManager *pApp) : Action(pApp) {}

void CutAction::ReadActionParameters()
{
	Input *pIn = pManager->GetGrid()->GetInput();
	Output *pOut = pManager->GetGrid()->GetOutput();
	pOut->PrintMessage("Select object to be cut");
	cellselected = pIn->GetCellClicked();
}

// Executes "Cut"
void CutAction::Execute()
{
	ReadActionParameters();
	Grid *pgrid = pManager->GetGrid();
	Output *pOut = pManager->GetGrid()->GetOutput();
	GameObject *selectedobj = pgrid->GetGameObjectfromCellPosition(cellselected);
	if (selectedobj != nullptr)
	{
		if (selectedobj->GetObjType() != belt)
		{
			pgrid->SetClipboard(selectedobj->clone());
			pgrid->DeleteGameObj(cellselected);
			pOut->PrintMessage("Object cut");
		}
		else if (selectedobj->GetObjType() == belt)
			pOut->PrintMessage("belts can't be cut");
	}
	else
	{
		pOut->PrintMessage("Didn't cut figure correctly");
	}
}