#pragma once

#include <iostream>
#include "WorkshopItem.h"
using namespace std;

class HackDeviceItem : public WorkshopItem
{
private:
    int cost;

public:
    // Constructor
    HackDeviceItem();
    void Execute(Grid *pGrid, Player *player);
    // Destructor
    virtual ~HackDeviceItem();
};
