#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "WaterPit.h"
class AddWaterPitAction : public Action
{
	CellPosition Pos;

public:
	AddWaterPitAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); // Reads action parameters
	virtual void Execute();				 // Creates a new Object
										 // then Sets this object to the GameObject Pointer of its Cell
	virtual ~AddWaterPitAction();
};
