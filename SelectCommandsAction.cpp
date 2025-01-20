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
    Command *SavedCommands = NULL;    // pointer to array of saved commands (has max size)
    Command *AvailableCommand = NULL; // pointer to the available command player can have

    int ActualMaxNumberOfCommands = 0;
    // actual number that the player can save to their savedCommands

    int numAvailablCommands = CurrentPlayer->GetHealth();
    // get's the size of the number of command the player have as available

    int MaxNumToSavedCommands = CurrentPlayer->GetNumOfSavedCommands(); // maximum size of saved-commands of the player - consider the extend memory
    ActualMaxNumberOfCommands = MaxNumToSavedCommands;

    if (numAvailablCommands > MaxNumToSavedCommands)
    {
        ActualMaxNumberOfCommands = MaxNumToSavedCommands;
    }
    else
        ActualMaxNumberOfCommands = numAvailablCommands;

    AvailableCommand = new Command[numAvailablCommands];
    SavedCommands = new Command[MaxNumToSavedCommands];

    for (int i = 0; i < numAvailablCommands; i++)
    {
        AvailableCommand[i] = NO_COMMAND;
        while (AvailableCommand[i] == NO_COMMAND)
            AvailableCommand[i] = static_cast<Command>(rand() % COMMANDS_COUNT);
    }
    // initialize the availableCommand array
    for (int i = 0; i < MaxNumToSavedCommands; i++)
    {
        SavedCommands[i] = NO_COMMAND;
    }
    // initialize the saved commands array

    // Create the Design Command Bar
    pOut->CreateCommandsBar(SavedCommands, MaxNumToSavedCommands, AvailableCommand, numAvailablCommands);
    int j = 0;
    int lastIndex = 0;
    int indexOfCommand = 0;
    for (int i = 0; i < ActualMaxNumberOfCommands; i++)
    {
        pOut->PrintMessage("Select the commands you want");
        indexOfCommand = pIn->GetSelectedCommandIndex();
        if (indexOfCommand != -1)
        {
            SavedCommands[i] = AvailableCommand[indexOfCommand];
            AvailableCommand[indexOfCommand] = NO_COMMAND;
            pOut->CreateCommandsBar(SavedCommands, MaxNumToSavedCommands, AvailableCommand, numAvailablCommands);
        }
        else
        {
            pGrid->PrintErrorMessage("ReEnter a valid command because wrong input");
        }

        if (SavedCommands[i] == NO_COMMAND)
        {

            while (SavedCommands[i] == NO_COMMAND)
            {

                pOut->PrintMessage("Select a valid command that you you want");
                indexOfCommand = pIn->GetSelectedCommandIndex();
                if (indexOfCommand != -1)
                {
                    SavedCommands[i] = AvailableCommand[indexOfCommand];
                    AvailableCommand[indexOfCommand] = NO_COMMAND;
                    pOut->CreateCommandsBar(SavedCommands, MaxNumToSavedCommands, AvailableCommand, numAvailablCommands);
                }
            }
        }
    }
    // saved commands are now stored
    CurrentPlayer->SetSavedCommands(SavedCommands);
    pOut->PrintMessage("You have selected all possible commands");
    pIn->GetCellClicked();
}

SelectCommandsAction::~SelectCommandsAction()
{
}