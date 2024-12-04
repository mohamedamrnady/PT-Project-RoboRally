#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode
	SET_FLAG_CELL, // Set Flag on a Cell
	EXIT,		   // Exit Application
	TO_PLAY_MODE,  // Go to Play Mode

	/// TODO: Add more action types of Design Mode
	//              ali    dool bto3 el design mode
	Add_Flag,
	Add_Antenna,
	Add_Belt,
	Add_Water_Pit,
	Add_Danger_Zone,
	Add_Workshop,
	Add_Rotating_Gear,
	Copy_Game_Object,
	Cut_Game_Object,
	Paste_Game_Object,
	Delete_Game_Object,
	Save_Grid,
	Load_OR_Open_Grid,
	Switch_to_Play_Mode,
	Exit,
	//

	//  [2] Actions of Play Mode

	EXECUTE_COMMANDS, // Execute the saved commands
	SELECT_COMMAND,	  // Select a command from the available ones to be executed

	TO_DESIGN_MODE, // Go to Design Mode

	/// TODO: Add more action types of Play Mode
	//                    ali   dool bto3 el play mode
	Select_Movement_Commands,
	Execute_Saved_Commands,
	Reboot_and_Repair,
	Use_Consumable,
	New_Game,
	Switch_to_Design_Mode,
	//
	//  [3] Others

	EMPTY,	   // Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA, // Inside Grid Area
	STATUS	   // Inside StatusBar Area
};

enum Direction // Directions of the game
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum Command
{
	NO_COMMAND,
	MOVE_FORWARD_ONE_STEP,
	MOVE_BACKWARD_ONE_STEP,
	MOVE_FORWARD_TWO_STEPS,
	MOVE_BACKWARD_TWO_STEPS,
	MOVE_FORWARD_THREE_STEPS,
	MOVE_BACKWARD_THREE_STEPS,
	ROTATE_CLOCKWISE,
	ROTATE_COUNTERCLOCKWISE,

	COMMANDS_COUNT,
};
#endif