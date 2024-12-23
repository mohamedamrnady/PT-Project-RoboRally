#pragma once

#include <iostream>
#include "WorkshopItem.h"
using namespace std;

class UpgradeLaserItem : public WorkshopItem
{
private:
    int cost;

public:
    // Constructor
    UpgradeLaserItem();
    void Execute(Grid *pGrid, Player *player);
    // Destructor
    virtual ~UpgradeLaserItem();
};
