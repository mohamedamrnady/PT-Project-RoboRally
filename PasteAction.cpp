#include "PasteAction.h"
#include "WaterPit.h"
#include "DangerZone.h"
#include "Workshop.h"
#include "RotatingGear.h"
#include "Flag.h"
#include "Antenna.h"
#include "BeltEnd.h"

PasteAction::PasteAction(ApplicationManager *pApp) : Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
	Output *pOut = pManager->GetGrid()->GetOutput();
	Input *pIn = pManager->GetGrid()->GetInput();
	pOut->PrintMessage("Click at the location to paste figure.");
	cellpasted = pIn->GetCellClicked();
	if (!cellpasted.IsValidCell())
	{
		pOut->PrintMessage("Invalid parameters! Please try again.");
		return;
	}
	pOut->ClearStatusBar();
}
/*
	bool added = pGrid->AddObjectToCell(pAntenna);

*/
// Executes "Paste"
void PasteAction::Execute()
{
	ReadActionParameters();
	Grid *pgrid = pManager->GetGrid();
	Output *pOut = pManager->GetGrid()->GetOutput();
	GameObject *clipboard = pgrid->GetClipboard();
	if (!clipboard)
	{
		pOut->PrintMessage("No figure is copied or cut. Can't paste.");
		return;
	}
	else
	{
		int type = clipboard->GetObjType();
		bool isfree = true;
		switch (type)
		{
		case flag:
		{
			if (pgrid->GetNumFlag() > 0)
			{
				pgrid->PrintErrorMessage("Error: Game already has an flag!");
				return;
			}
			else
			{
				Flag *tempF = new Flag(cellpasted);
				isfree = pgrid->AddObjectToCell(tempF);
				pgrid->SetNumFlag(1);
			}
			break;
		}
		case antenna:
		{
			if (pgrid->GetNumAntennas() > 0)
			{
				pgrid->PrintErrorMessage("Error: Game already has an antenna!");
				return;
			}
			else
			{
				Antenna *tempantenna = new Antenna(cellpasted);
				isfree = pgrid->AddObjectToCell(tempantenna);
				pgrid->SetNumAntennas(1);
			}
			break;
		}
		case water_pit:
		{
			WaterPit *tempWP = new WaterPit(cellpasted);
			isfree = pgrid->AddObjectToCell(tempWP);
			pgrid->SetnumWaterPits((pgrid->GetnumWaterPits()) + 1);
			break;
		}
		case danger_zone:
		{
			DangerZone *tempDZ = new DangerZone(cellpasted);
			isfree = pgrid->AddObjectToCell(tempDZ);
			pgrid->SetnumDangerZones((pgrid->GetnumDangerZones()) + 1);
			break;
		}
		case workshop:
		{
			Workshop *tempWorkshop = new Workshop(cellpasted);
			isfree = pgrid->AddObjectToCell(tempWorkshop);
			pgrid->SetnumWorkshops((pgrid->GetnumWorkshops()) + 1);
			break;
		}
		case rotating_gear:
		{
			RotatingGear *tempRG = new RotatingGear(*(dynamic_cast<RotatingGear *>(clipboard)));
			isfree = pgrid->AddObjectToCell(tempRG);
			pgrid->SetnumRotatingGears((pgrid->GetnumRotatingGears()) + 1);
			break;
		}
		case belt_end:
		{
			BeltEnd *tempBE = new BeltEnd(*(dynamic_cast<BeltEnd *>(clipboard)));
			isfree = pgrid->AddObjectToCell(tempBE);
			break;
		}

			//	return dynamic_cast<DangerZone *>(pGameObject);
		}

		if (isfree)
			pOut->PrintMessage("Object pasted");
		else
			pOut->PrintMessage("Cell is not free");
	}
	// pManager->paste(p1.x, p1.y);
}

/*
	 Antenna *pAntenna = new Antenna(Pos);

Output *pOut = pGrid->GetOutput();

 bool added = pGrid->AddObjectToCell(pAntenna);
	 */

/*

Point p1;
	p1.x = a;
	p1.y = b;
	Point p2;
	p2.x = 0;
	p2.y = 0;
	Point p3;
	p3.x = 0;
	p3.y = 0;
	Output* pOut = GetOutput();
	Input* pIn = GetInput();
	CSquare* S;
	CRectangle* R;
	CCircle* C;
	CTriangle* T;
	CHexagon* H;

	if (Clipboard != nullptr) {
		//CFigure* copiedfigure = Clipboard->clone();
		if (SelectedFig->IsCut()) {
			DElete();
		}
		GfxInfo figInfo= Clipboard->GetFigInfo();
		switch (Clipboard->GetFigType()) {
		case SQUARE:
			S = new CSquare(p1, figInfo);
			AddFigure(S);
			S->Draw(pOut);
			break;
		case RECTANGLE:
		{
			Point OG_p1r = Clipboard->GetPoint1();
			Point OG_p2r = Clipboard->GetPoint2();


			double v1x = OG_p2r.x - OG_p1r.x;
			double v1y = OG_p2r.y - OG_p1r.y;
			p2.x = p1.x + v1x;
			p2.y = p1.y + v1y;
			R = new CRectangle(p1, p2, figInfo);
			AddFigure(R);
			R->Draw(pOut);
		}
			break;
		case TRIANGLE:
		{
			Point OG_p1t = Clipboard->GetPoint1();
			Point OG_p2t = Clipboard->GetPoint2();
			Point OG_p3t = Clipboard->GetPoint3();
			findOtherCoordinates(OG_p1t, OG_p2t, OG_p3t, p1, p2, p3);
			T = new CTriangle(p1, p2, p3, figInfo);
			AddFigure(T);
			T->Draw(pOut);
		}
			break;
		case HEXAGON:
		{
			H = new CHexagon(p1, figInfo);
			AddFigure(H);
			H->Draw(pOut);
		}
			break;
		case CIRCLE:
		{
			Point OG_p1c = Clipboard->GetPoint1();
			Point OG_p2c = Clipboard->GetPoint2();
			double radius = sqrt(pow(OG_p1c.x - OG_p2c.x, 2) + pow(OG_p1c.y - OG_p2c.y, 2));
			p2.x = p1.x + radius;
			p2.y = p1.y;
			C = new CCircle(p1, p2, figInfo);
			AddFigure(C);
			C->Draw(pOut);
		}
			break;
		}


	}
*/