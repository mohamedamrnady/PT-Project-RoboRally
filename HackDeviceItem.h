#pragma once

#include <iostream>
#include "WorkshopItem.h"
using namespace std;

class HackDeviceItem : public WorkshopItem
{
public:
    // Constructor
    HackDeviceItem(int c);
    virtual void Execute(Grid *pGrid, Player *player);
    // Destructor
    virtual ~HackDeviceItem();
};
