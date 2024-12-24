#include "UpgradeLaserItem.h"

UpgradeLaserItem::UpgradeLaserItem(int c) : WorkshopItem(c)
{
}

void UpgradeLaserItem::Execute(Grid *pGrid, Player *player)
{
    player->UpgradeLaserType();
    pGrid->GetOutput()->PrintMessage("Using Double laser.");
}

UpgradeLaserItem::~UpgradeLaserItem()
{
}
