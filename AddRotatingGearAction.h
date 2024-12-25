#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "RotatingGear.h"
class AddRotatingGearAction : public Action
{
	CellPosition gearPos; // The position of the rotating gear
	bool clockwise;		  // bool value indicating if the gear will be in clockwise direction if true direction will be clockwise if false direction will be anticlockwise
public:
	AddRotatingGearAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); // Reads action parameters
	virtual void Execute();				 // Creates a new rotating gear Object
										 // then Sets this rotating gear object to the GameObject Pointer of its Cell
	virtual ~AddRotatingGearAction();
};
