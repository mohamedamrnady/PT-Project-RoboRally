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

    pOut->ClearCommandsBar();
    Player *CurrentPlayer = pGrid->GetCurrentPlayer();
    Command *SavedCommands;
    int commandSaved = 0;

    Command AvailableCommand[10];
    if (CurrentPlayer->GetHealth() > 5)
    {
        SavedCommands = new Command[5];
        commandSaved = 5;
    }
    else if (CurrentPlayer->GetHealth() > 0)
    {
        SavedCommands = new Command[CurrentPlayer->GetHealth()];
        commandSaved = CurrentPlayer->GetHealth();
    }

    for (int i = 0; i < commandSaved; i++)
    {
        SavedCommands[i] = NO_COMMAND;
    }
    for (int i = 0; i < 10; i++)
    {
        AvailableCommand[i] = static_cast<Command>(rand() % COMMANDS_COUNT);
    }

    // Create the Design Command Bar
    pOut->CreateCommandsBar(SavedCommands, commandSaved, AvailableCommand, 10);
    int j = 0;
    for (int i = 0; i < commandSaved; i++)
    {
        pOut->PrintMessage("Select the commands you want");
        int indexOfCommand = pIn->GetSelectedCommandIndex();
        if (indexOfCommand != -1)
        {
            SavedCommands[j] = AvailableCommand[i];
            j++;
            AvailableCommand[i] = NO_COMMAND;
            pOut->CreateCommandsBar(SavedCommands, commandSaved, AvailableCommand, 10 - j);
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