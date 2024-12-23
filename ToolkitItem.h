#pragma once

#include <iostream>
#include "WorkshopItem.h"
using namespace std;

class ToolkitItem : public WorkshopItem
{
private:
    int cost;

public:
    // Constructor
    ToolkitItem();
    void Execute(Grid *pGrid, Player *player);
    // Destructor
    virtual ~ToolkitItem();
};
