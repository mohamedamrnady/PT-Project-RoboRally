#include "ApplicationManager.h"

#include "Grid.h"
#include "AddBeltAction.h"
#include "AddRotatingGearAction.h"
#include "AddFlagAction.h"
#include "AddDangerZoneAction.h"
#include "AddWaterPitAction.h"
#include "AddWorkshopAction.h"
#include "AddAntennaAction.h"
#include "Delete_Action.h"
#include "Switch_to_Play_Mode.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include "CopyAction.h"
#include "CutAction.h"
#include "PasteAction.h"
#include "CreatePlayModeToolBarAction.h"   // Include the correct header file for CreatePlayMode
#include "CreateDesignModeToolBarAction.h" // Include the correct header file for CreateDesignMode

/// TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid *ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action *pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case Add_Belt:
		pAct = new AddBeltAction(this);
		break;
	case Add_Rotating_Gear:
		// create an object of AddRotatingGearAction here
		pAct = new AddRotatingGearAction(this);
		break;
	case Add_Flag:
		// create an object of AddFlagAction here
		pAct = new AddFlagAction(this);
		break;
	case Delete_Game_Object:
		pAct = new Delete_Action(this);
		break;
		//SaveAction
	case Save_Grid:
		pAct = new SaveAction(this);
		break;
	case Load_OR_Open_Grid:
		pAct = new LoadAction(this);
		break;
	case Copy_Game_Object:
		pAct = new CopyAction(this);
		break;
	case Cut_Game_Object:
		pAct = new CutAction(this);
		break;
	case Paste_Game_Object:
		pAct = new PasteAction(this);
		break;
	case EXIT:
		break;
	case TO_PLAY_MODE:								  // TODO:
		pAct = new Switch_to_Play_Mode(this); // Use the correct class name
		break;

	case TO_DESIGN_MODE:
		pAct = new CreateDesignModeToolBarAction(this);
		break;

		/// TODO: Add a case for EACH Action type in the Design mode or Play mode
	case Add_Danger_Zone:
		pAct = new AddDangerZoneAction(this);
		break;
	case Add_Water_Pit:
		pAct = new AddWaterPitAction(this);
		break;
	case Add_Workshop:
		pAct = new AddWorkshopAction(this);
		break;
	case Add_Antenna:
		pAct = new AddAntennaAction(this);
		break;

	case STATUS: // a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}

//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}

//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}