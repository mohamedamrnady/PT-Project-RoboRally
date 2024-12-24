#include "HackDeviceItem.h"

HackDeviceItem::HackDeviceItem(int c) : WorkshopItem(c)
{
}

void HackDeviceItem::Execute(Grid *pGrid, Player *player)
{
    pGrid->AdvanceCurrentPlayer();
    Player *opponent = pGrid->GetCurrentPlayer();
    pGrid->AdvanceCurrentPlayer();
    opponent->SetIsHacked(true);
    pGrid->GetOutput()->PrintMessage("Hacking device is applied");
}

HackDeviceItem::~HackDeviceItem()
{
}
