#pragma once
#define MAX_ITEM_COUNT 3

#include "Player.h"
#include <iostream>
using namespace std;

class WorkshopItem
{
protected:
    int const cost;

public:
    // Constructor
    WorkshopItem();
    // virtual void ReadActionParameters() = 0; // Reads parameters required for action to execute
    //                                          // (code depends on action type so virtual)

    virtual void Execute(Grid *pGrid, Player *player) = 0; // Executes action

    // Destructor
    virtual ~WorkshopItem();
};
