#include "Switch_to_Play_Mode.h"

Switch_to_Play_Mode::Switch_to_Play_Mode(ApplicationManager* pApp) :Action(pApp)
{
}

void Switch_to_Play_Mode::ReadActionParameters() {

}

void Switch_to_Play_Mode::Execute() {
	Output* pOut = pManager->GetOutput();

	pOut->ClearStatusBar();

	//ofstream File;
	pOut->PrintMessage("SWITCHED TO PLAY MODE");

	/*File.open("temp.txt");
	Grid* gridptr = gridptr = pManager->GetGrid();
	pManager->ExecuteAction(Save_Grid);
	File.close();*/


	pOut->CreatePlayModeToolBar();
	//pOut->CreateCommandsBar(Command savedCommands[], int savedCommandsCount, Command availableCommands[], int availableCommandsCount) const;
	//pOut->PrintPlayersInfo();

	//pOut->CreateCommandsBar();





}


Switch_to_Play_Mode::~Switch_to_Play_Mode()
{
}