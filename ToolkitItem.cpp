#include "ToolkitItem.h"

ToolkitItem::ToolkitItem(int c) : WorkshopItem(c)
{
}

void ToolkitItem::Execute(Grid *pGrid, Player *player)
{
    player->SetHealth(10);
    pGrid->GetOutput()->PrintMessage("Toolkit is applied");
}

ToolkitItem::~ToolkitItem()
{
}
