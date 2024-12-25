#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Workshop.h"

class AddWorkshopAction : public Action
{
    CellPosition Pos;

public:
    AddWorkshopAction(ApplicationManager *pApp);
    virtual void ReadActionParameters(); // Reads action parameters
    virtual void Execute();              // Creates a new Object
                                         // then Sets this object to the GameObject Pointer of its Cell
    virtual ~AddWorkshopAction();
};