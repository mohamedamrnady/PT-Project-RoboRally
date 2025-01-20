#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode
	EXIT,		  // Exit Application
	TO_PLAY_MODE, // Go to Play Mode

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
	//

	//  [2] Actions of Play Mode

	TO_DESIGN_MODE, // Go to Design Mode

	/// TODO: Add more action types of Play Mode
	//                    ali   dool bto3 el play mode
	EXECUTE_COMMANDS, // Execute the saved commands
	SELECT_COMMAND,	  // Select a command from the available ones to be executed
	Reboot_and_Repair,
	Use_Consumable,
	New_Game,
	//
	//  [3] Others

	EMPTY,	   // Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA, // Inside Grid Area
	STATUS	   // Inside StatusBar Area
};

enum Direction // Directions of the game
{
	UP,
	RIGHT,
	DOWN,
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

enum WorkshopItemTypes
{
	HACK_DEVICE,
	TOOLKIT,
	EXTENDED_MEMORY,
	UPGRADE_LASER,

	WORKSHOP_ITEMS_COUNT,
};

// either flag, water pit, danger zone, belt, workshop, antenna or rotating gear
enum GameObj
{
	flag,
	water_pit,
	danger_zone,
	belt,
	belt_end,
	workshop,
	antenna,
	rotating_gear,
};
#endif