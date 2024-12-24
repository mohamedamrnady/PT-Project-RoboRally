#include "ExtendedMemoryItem.h"

ExtendedMemoryItem::ExtendedMemoryItem(int c) : WorkshopItem(c)
{
}

void ExtendedMemoryItem::Execute(Grid *pGrid, Player *player)
{
    player->SetNumOfSavedCommands(6);
    pGrid->GetOutput()->PrintMessage("Extended Memory is applied");
}

ExtendedMemoryItem::~ExtendedMemoryItem()
{
}
