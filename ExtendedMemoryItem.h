#pragma once

#include <iostream>
#include "WorkshopItem.h"
using namespace std;

class ExtendedMemoryItem : public WorkshopItem
{
private:
    int cost;

public:
    // Constructor
    ExtendedMemoryItem();
    void Execute(Grid *pGrid, Player *player);
    // Destructor
    virtual ~ExtendedMemoryItem();
};
