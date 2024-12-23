#include "SelectCommandsAction.h"

SelectCommandsAction::SelectCommandsAction(ApplicationManager *pApp) : Action(pApp)
{
}

void SelectCommandsAction::ReadActionParameters()
{
    // No parameters to read for this action
}

void SelectCommandsAction::Execute()
{
    // Get a Pointer to the Output Interface
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();

    Player *CurrentPlayer = pGrid->GetCurrentPlayer();

    Command AvailableCommand[10];
    Command *SavedCommands = new Command[5];

    for (int i = 0; i < 5; i++)
    {
        SavedCommands[i] = NO_COMMAND;
    }
    for (int i = 0; i < 10; i++)
    {
        AvailableCommand[i] = static_cast<Command>(rand() % COMMANDS_COUNT);
    }

    // Create the Design Command Bar
    pOut->CreateCommandsBar(SavedCommands, 5, AvailableCommand, 10);
    int j = 0;
    for (int i = 0; i < CurrentPlayer->GetHealth(); i++)
    {
        pOut->PrintMessage("Select the commands you want");
        int indexOfCommand = pIn->GetSelectedCommandIndex();
        if (indexOfCommand != -1)
        {
            SavedCommands[j++] = AvailableCommand[i];
            pOut->CreateCommandsBar(SavedCommands, 5, AvailableCommand, 10);
        }
        else
            pGrid->PrintErrorMessage("Missing a command because wrong input");
    }
    // saved commands are now stored
    CurrentPlayer->SetSavedCommands(SavedCommands);
}

SelectCommandsAction::~SelectCommandsAction()
{
}