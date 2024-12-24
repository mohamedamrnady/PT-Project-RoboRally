#pragma once

#include <iostream>
#include "WorkshopItem.h"
using namespace std;

class ExtendedMemoryItem : public WorkshopItem
{
public:
    // Constructor
    ExtendedMemoryItem(int c);
    virtual void Execute(Grid *pGrid, Player *player);
    // Destructor
    virtual ~ExtendedMemoryItem();
};
