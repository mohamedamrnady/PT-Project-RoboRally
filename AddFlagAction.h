#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Flag.h"
#include "Cell.h"
class AddFlagAction : public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition flagPos; // 1- The position of the flag
public:
	AddFlagAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); // Reads action parameters

	virtual void Execute(); // Creates a new flag Object
							// then Sets this flag object to the GameObject Pointer of its Cell

	~AddFlagAction();
};
