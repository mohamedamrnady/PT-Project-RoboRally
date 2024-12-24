#pragma once

#include "Player.h"
#include <iostream>
using namespace std;

class WorkshopItem
{
protected:
    int cost;

public:
    // Constructor
    WorkshopItem(int c);
    // virtual void ReadActionParameters() = 0; // Reads parameters required for action to execute
    //                                          // (code depends on action type so virtual)

    virtual void Execute(Grid *pGrid, Player *player) = 0; // Executes action
    int GetCost() const;                                   // Returns cost of item

    // Destructor
    virtual ~WorkshopItem();
};
