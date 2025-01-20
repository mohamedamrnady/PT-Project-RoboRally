#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Belt.h"
#include "BeltEnd.h"

class AddBeltAction : public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition startPos; // 1- The start position of the belt
	CellPosition endPos;   // 2- The end position of the belt

	// Note: These parameters should be read in ReadActionParameters()
public:
	AddBeltAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); // Reads AddBeltAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new belt Object
							// then Sets this belt object to the GameObject Pointer of its Cell

	virtual ~AddBeltAction();
};
