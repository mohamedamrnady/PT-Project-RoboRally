#include "UseConsumablesAction.h"
#include "Player.h"
#include "Workshop.h"

UseConsumablesAction::UseConsumablesAction(ApplicationManager *pApp) : Action(pApp)
{
}

void UseConsumablesAction::ReadActionParameters()
{
}

void UseConsumablesAction::Execute()
{
	Grid *pGrid = pManager->GetGrid();
	Player *player = pGrid->GetCurrentPlayer();
	Output *pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	Workshop *workshop = player->GetWorkshop();
	if (!workshop)
	{
		pOut->PrintMessage("You need to access a workshop first.");
		return;
	}
	WorkshopItemTypes *availableItems = player->GetItems();

	// form the available items message
	string message = "Available Items: ";
	for (int i = 0; i < WORKSHOP_ITEMS_COUNT; i++)
	{
		if (availableItems[i] == HACK_DEVICE)
		{
			message += to_string(i) + ") Hack Device ";
		}
		else if (availableItems[i] == TOOLKIT)
		{
			message += to_string(i) + ") Toolkit ";
		}
	}

	pOut->PrintMessage(message);
	int choice = pIn->GetInteger(pOut);
	if (availableItems[choice] != static_cast<WorkshopItemTypes>(-1))
		workshop->ExecuteItem(pGrid, player, availableItems[choice]);
	else
		pOut->PrintMessage("Invalid choice.");
}

UseConsumablesAction::~UseConsumablesAction()
{
}
