#include "Workshop.h"
#include "HackDeviceItem.h"
#include "ToolkitItem.h"
#include "Player.h"
#include "ExtendedMemoryItem.h"
#include "UpgradeLaserItem.h"

Workshop::Workshop(const CellPosition &workshopPosition) : GameObject(workshopPosition)
{
	// initializes the workshop items
	workshopItems[HACK_DEVICE] = new HackDeviceItem(1); // cost = 1 health point
	workshopItems[TOOLKIT] = new ToolkitItem(1);
	workshopItems[EXTENDED_MEMORY] = new ExtendedMemoryItem(1);
	workshopItems[UPGRADE_LASER] = new UpgradeLaserItem(1);
}

void Workshop::Draw(Output *pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid *pGrid, Player *pPlayer)
{
	pPlayer->SetWorkshop(this);
	Output *pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	pOut->PrintMessage("Choose what you want to buy: 1) Weapons  2) Devices  3) Consumables 4) Repair");
	int choice = pIn->GetInteger(pOut);
	switch (choice)
	{
	case 1:
		pOut->PrintMessage("Choose what you want to buy: 1) Upgrade Laser");
		choice = pIn->GetInteger(pOut);
		switch (choice)
		{
		case 1:
			workshopItems[UPGRADE_LASER]->Execute(pGrid, pPlayer); // Upgrade Laser applied instead of adding to user items
			pPlayer->SetHealth(pPlayer->GetHealth() - workshopItems[UPGRADE_LASER]->GetCost(), pGrid);
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
			workshopItems[EXTENDED_MEMORY]->Execute(pGrid, pPlayer); // Exteneded Memory applied instead of adding to user items
			pPlayer->SetHealth(pPlayer->GetHealth() - workshopItems[UPGRADE_LASER]->GetCost(), pGrid);
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
			pPlayer->AddItem(HACK_DEVICE);
			pPlayer->SetHealth(pPlayer->GetHealth() - workshopItems[UPGRADE_LASER]->GetCost(), pGrid);
			pOut->PrintMessage("Hack Device is added to your items.");
			break;
		case 2:
			pPlayer->AddItem(TOOLKIT);
			pPlayer->SetHealth(pPlayer->GetHealth() - workshopItems[UPGRADE_LASER]->GetCost(), pGrid);
			pOut->PrintMessage("Toolkit is added to your items.");
			break;
		default:
			pOut->PrintMessage("Invalid choice.");
			break;
		}
		break; // related to commands
	case 4:
		pPlayer->SetHealth(10, pGrid);
		pOut->PrintMessage("Repaired successfully.");
		break;
	default:
		pOut->PrintMessage("Invalid choice.");
		break;
	}
}

void Workshop::ExecuteItem(Grid *pGrid, Player *pPlayer, WorkshopItemTypes item)
{
	workshopItems[item]->Execute(pGrid, pPlayer);
}

void Workshop::Load(ifstream &Infile)
{
	int cellnum;
	Infile >> cellnum;
	position.SetCellNum(cellnum);
}

int Workshop::GetObjType()
{
	return workshop;
}

void Workshop::Save(ofstream &OutFile, int t)
{
	if (t == workshop)
		OutFile << position.GetCellNum() << endl;
}

GameObject *Workshop::clone() const
{
	return new Workshop(*this);
}

Workshop::~Workshop()
{
	for (int i = 0; i < WORKSHOP_ITEMS_COUNT; i++)
		delete workshopItems[i];
}
