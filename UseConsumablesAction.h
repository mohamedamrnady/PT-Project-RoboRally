#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "DangerZone.h"
class UseConsumablesAction : public Action
{
public:
	UseConsumablesAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); // Reads action parameters
	virtual void Execute();				 // Creates a new Object
										 // then Sets this object to the GameObject Pointer of its Cell
	virtual ~UseConsumablesAction();
};
