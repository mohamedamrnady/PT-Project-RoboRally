#pragma once

#include "UI_Info.h"
#include "CellPosition.h"

// Class forward declarations (their #include is in the .cpp file)
class Grid;
class Output;
class GameObject;
class Belt;
class WaterPit;
class Flag;
class Player;
class DangerZone;
class RotatingGear;
class Workshop;
class Antenna;
class Cell
{
	const CellPosition position; // the cell position (vCell and hCell) --> will not change after the Cell is constructed

	GameObject *pGameObject; // a pointer to the GameObject existing in the Cell (if any)
							 // if no GameObject in this Cell, pGameObject should be NULL

public:
	Cell(const CellPosition &pos); // A constructor initializes the cell position with the passed CellPosition
	Cell(int v, int h);			   // A constructor initializes the cell position with the passed vCell and hCell

	// ======= Setters and Getters Functions =======

	CellPosition GetCellPosition() const; // A getter for the "position" data member

	bool SetGameObject(GameObject *pGObj); // A setter for pGameObject of the cell
										   // It does NOT add the object and returns false if the cell already contains one
	GameObject *GetGameObject() const;	   // A getter for pGameObject of the cell

	int DeleteGameObj(const CellPosition &selected_cell); // returns type of object deleted

	// TODO implement similar functions to check if a cell has a specific gameobject if needed
	Belt *HasBelt() const; // Checks if pGameObject is a Belt Then returns true if it is a belt or returns NULL if not belt
	Flag *HasFlag() const; // Checks if pGameObject is a Flag Then returns true if it is a flag or returns NULL if not flag
	RotatingGear *HasRotatingGear() const;
	Workshop *HasWorkshop() const;
	WaterPit *HasWaterPit() const;
	DangerZone *HasDangerZone() const;
	Antenna *HasAntenna() const;
	// ======= Drawing Functions =======

	void DrawCellOrWaterPitOrDangerZone(Output *pOut) const; // Draws the Cell either has waterpit or dangerzone(either of the gameobjects changes the cell color)
	// TODO:complete the implementation
	//  Draws other game objects(excluding danger zone and waterpit)  of the Cell if found
	//  The two Draw functions are separated because we should draw all cells first
	//  then draw all other game objects, in order to avoid overlapping
	//  or drawing cell's background over existing game objects
	void DrawGameObject(Output *pOut) const;
};
