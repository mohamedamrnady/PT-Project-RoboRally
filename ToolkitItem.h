#pragma once

#include <iostream>
#include "WorkshopItem.h"
using namespace std;

class ToolkitItem : public WorkshopItem
{
public:
    // Constructor
    ToolkitItem(int c);
    virtual void Execute(Grid *pGrid, Player *player);
    // Destructor
    virtual ~ToolkitItem();
};
