#include "SaveAction.h"
#include <iostream>

SaveAction::SaveAction(ApplicationManager *pApp) : Action(pApp)
{
    gridptr = pApp->GetGrid();
}
void SaveAction::ReadActionParameters()
{
    Input *pIn = pManager->GetGrid()->GetInput();
    Output *pOut = pManager->GetGrid()->GetOutput();
    pOut->PrintMessage("Enter File Name (don't enter .txt)"); // Read the file name
    inputstring = pIn->GetSrting(pOut);
}

void SaveAction::Execute() // fee moshkilla fel gameobj w el gridptr cuz they are uninitialised w idk what to initialise them with
{
    Output *pOut = pManager->GetGrid()->GetOutput();
    ReadActionParameters();
    pOut->ClearStatusBar();

    string fileName = inputstring + ".txt"; // so it's a textfile

    ofstream OutputFile(fileName);
    if (!OutputFile)
    {
        pOut->PrintMessage("couldn't save file");
        return;
    }

    OutputFile << gridptr->GetNumFlag() << endl; // flags
    gridptr->SaveAll(OutputFile, flag);

    OutputFile << gridptr->GetnumWaterPits() << endl; // water pits
    gridptr->SaveAll(OutputFile, water_pit);

    OutputFile << gridptr->GetnumDangerZones() << endl; // danger zones
    gridptr->SaveAll(OutputFile, danger_zone);

    OutputFile << gridptr->GetnumBelts() << endl; // belts
    gridptr->SaveAll(OutputFile, belt);

    OutputFile << gridptr->GetnumWorkshops() << endl; // workshops
    gridptr->SaveAll(OutputFile, workshop);

    OutputFile << gridptr->GetNumAntennas() << endl; // antennas
    gridptr->SaveAll(OutputFile, antenna);

    OutputFile << gridptr->GetnumRotatingGears() << endl; // rotating gears
    gridptr->SaveAll(OutputFile, rotating_gear);
    OutputFile.close();
    pOut->PrintMessage("File is saved");
}
