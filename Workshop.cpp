#include "Workshop.h"
#include "HackDeviceItem.h"
#include "ToolkitItem.h"
#include "Player.h"
#include "ExtendedMemoryItem.h"
#include "UpgradeLaserItem.h"

Workshop::Workshop(const CellPosition &workshopPosition) : GameObject(workshopPosition)
{
	// initializes the workshop items
	workshopItems[0] = new HackDeviceItem();
	workshopItems[1] = new ToolkitItem();
	workshopItems[2] = new ExtendedMemoryItem();
	workshopItems[3] = new UpgradeLaserItem();
}

void Workshop::Draw(Output *pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid *pGrid, Player *pPlayer)
{
	Output *pOut;
	Input *pIn;

	pOut->PrintMessage("Choose what you want to buy: 1) Weapons  2) Devices  3) Consumables");
	int choice = pIn->GetInteger(pOut);
	switch (choice)
	{
	case 1:
		pOut->PrintMessage("Choose what you want to buy: 1) Upgrade Laser");
		choice = pIn->GetInteger(pOut);
		switch (choice)
		{
		case 1:
			workshopItems[3]->Execute(pGrid, pPlayer); // Upgrade Laser applied instead of adding to user items
			pOut->PrintMessage("Using Double laser.");
			break;
		default:
			pOut->PrintMessage("No upgrades applied.");
			break;
		}
		break;

	case 2:
		pOut->PrintMessage("Choose what you want to buy: 1) Extended Memory");
		choice = pIn->GetInteger(pOut);
		switch (choice)
		{
		case 1:
			workshopItems[2]->Execute(pGrid, pPlayer); // Exteneded Memory applied instead of adding to user items
			pOut->PrintMessage("Extended Memory is applied");
			break;
		default:
			pOut->PrintMessage("Invalid choice.");
			break;
		}
		break;
	case 3:
		pOut->PrintMessage("Choose what you want to buy: 1) Hack Device  2) Toolkit");
		choice = pIn->GetInteger(pOut);
		switch (choice)
		{
		case 1:
			pPlayer->AddItem(workshopItems[0]);
			pOut->PrintMessage("Hack Device is added to your items.");
			break;
		case 2:
			pPlayer->AddItem(workshopItems[1]);
			pOut->PrintMessage("Toolkit is added to your items.");
			break;
		default:
			pOut->PrintMessage("Invalid choice.");
			break;
		}
		break; // related to commands
	default:
		pOut->PrintMessage("Invalid choice.");
		break;
	}
}

Workshop::~Workshop()
{
	delete[] workshopItems;
}
