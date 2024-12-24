#pragma once

#include <iostream>
#include "WorkshopItem.h"
using namespace std;

class UpgradeLaserItem : public WorkshopItem
{
public:
    // Constructor
    UpgradeLaserItem(int c);
    virtual void Execute(Grid *pGrid, Player *player);
    // Destructor
    virtual ~UpgradeLaserItem();
};
