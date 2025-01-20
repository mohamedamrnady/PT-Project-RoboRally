#include "CopyAction.h"
CopyAction::CopyAction(ApplicationManager *pApp) : Action(pApp) {}

void CopyAction::ReadActionParameters()
{
	Input *pIn = pManager->GetGrid()->GetInput();
	Output *pOut = pManager->GetGrid()->GetOutput();
	pOut->PrintMessage("Select object to be copied");
	cellselected = pIn->GetCellClicked();
}

void CopyAction::Execute()
{
	ReadActionParameters();
	Grid *pgrid = pManager->GetGrid();
	Output *pOut = pManager->GetGrid()->GetOutput();
	GameObject *selectedobj = pgrid->GetGameObjectfromCellPosition(cellselected);

	if (selectedobj != nullptr)
	{

		if ((selectedobj->GetObjType() != flag) && (selectedobj->GetObjType() != antenna) && (selectedobj->GetObjType() != belt))
		{
			pgrid->SetClipboard(selectedobj->clone());
			pOut->PrintMessage("Copied object");
		}
		else if (selectedobj->GetObjType() == antenna)
			pOut->PrintMessage("antennas can't be copied");
		else if (selectedobj->GetObjType() == flag)
			pOut->PrintMessage("flags can't be copied");
		else if (selectedobj->GetObjType() == belt)
			pOut->PrintMessage("belts can't be copied");
	}
	else
	{
		pOut->PrintMessage("Didn't copy figure correctly");
	}
}