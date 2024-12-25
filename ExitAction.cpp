#include "ExitAction.h"

ExitAction::ExitAction(ApplicationManager *pApp) : Action(pApp)
{
	GameEnded = false;
	// Initializes the pManager pointer of Action with the passed pointer
}

void ExitAction::ReadActionParameters()
{

	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
}

void ExitAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first
	// and hence initializes its data members
	ReadActionParameters();
}

ExitAction::~ExitAction()
{
}