#include "ToolkitItem.h"

ToolkitItem::ToolkitItem(int c) : WorkshopItem(c)
{
}

void ToolkitItem::Execute(Grid *pGrid, Player *player)
{
    player->SetHealth(10, pGrid);
    pGrid->GetOutput()->PrintMessage("Toolkit is applied");
}

ToolkitItem::~ToolkitItem()
{
}
