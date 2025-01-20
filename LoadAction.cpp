#include "LoadAction.h"
#include "Belt.h"
#include "Antenna.h"
#include "DangerZone.h"
#include "Flag.h"
#include "RotatingGear.h"
#include "WaterPit.h"
#include "Workshop.h"
#include "GameObject.h"
#include "Input.h"
#include "Output.h"
#include <iostream>
#include <fstream>
#include "BeltEnd.h"
using namespace std;

LoadAction::LoadAction(ApplicationManager *pApp) : Action(pApp)
{
	gridptr = pManager->GetGrid();
}

void LoadAction::ReadActionParameters()
{
	Output *pOut = pManager->GetGrid()->GetOutput();
	Input *pIn = pManager->GetGrid()->GetInput();
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		pOut->PrintMessage("Please enter the file name to be loaded (without .txt please)");
		inputstring = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();
	}
	else
		pOut->PrintMessage("file couldn't be loaded");
}

void LoadAction::Execute()
{

	ReadActionParameters();
	string filename = inputstring + ".txt";
	ifstream File(filename);

	Output *pOut = gridptr->GetOutput();
	Input *pIn = pManager->GetGrid()->GetInput();
	if (File.is_open())
	{
		pOut->PrintMessage("File is successfully loaded");
		CellPosition emptypos;
		int num;
		File >> num;
		if (!File.fail())
		{
			for (int i = 0; i < num; i++)
			{
				Flag *tempflag = new Flag(emptypos);
				tempflag->Load(File);
				gridptr->AddObjectToCell(tempflag);
			}

			File >> num;
			if (!File.fail())
			{
				for (int i = 0; i < num; i++)
				{
					WaterPit *tempwp = new WaterPit(emptypos);
					tempwp->Load(File);
					gridptr->AddObjectToCell(tempwp);
				}

				File >> num;
				if (!File.fail())
				{
					for (int i = 0; i < num; i++)
					{
						DangerZone *tempDG = new DangerZone(emptypos);
						tempDG->Load(File);
						gridptr->AddObjectToCell(tempDG);
					}

					File >> num;
					if (!File.fail())
					{
						for (int i = 0; i < num; i++)
						{
							Belt *tempbelt = new Belt(emptypos, emptypos);
							tempbelt->Load(File);
							gridptr->AddObjectToCell(tempbelt);
							// tempbelt.Draw(pOut);
						}
						{
							Belt *tempbelt = new Belt(emptypos, emptypos);
							BeltEnd *tempbeltend = new BeltEnd(emptypos);
							tempbelt->Load(File);
							tempbeltend->Load(File);
							gridptr->AddObjectToCell(tempbelt);
							gridptr->AddObjectToCell(tempbeltend);
							// tempbelt.Draw(pOut);
						}
						File >> num;
						if (!File.fail())
						{
							for (int i = 0; i < num; i++)
							{
								Workshop *tempwshop = new Workshop(emptypos);
								tempwshop->Load(File);
								gridptr->AddObjectToCell(tempwshop);
								// tempwshop.Draw(pOut);
							}

							File >> num;
							if (!File.fail())
							{
								for (int i = 0; i < num; i++)
								{
									Antenna *tempantenna = new Antenna(emptypos);
									tempantenna->Load(File);
									gridptr->AddObjectToCell(tempantenna);
									// tempantenna.Draw(pOut);
								}
								File >> num;
								if (!File.fail())
								{
									for (int i = 0; i < num; i++)
									{
										RotatingGear *temprg = new RotatingGear(emptypos, true);
										temprg->Load(File);
										gridptr->AddObjectToCell(temprg);
										// temprg.Draw(pOut);
									}
								}
							}
						}
					}
				}
			}
		}
		File.close();
	}
	else
		pOut->PrintMessage("Unable to open file");
}