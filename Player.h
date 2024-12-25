#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell *pCell; // pointer to the current Cell of the player

	const int playerNum; // the player number (from 0 to MaxPlayerCount-1)
						 // player number does NOT change after construction (const.)

	int stepCount;			 // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	Direction currDirection; // Current Direction of the player
	int health;				 // Player's current health points

	// owned equipments
	// carried consumables
	// carried laser type (default, double laser)
	// isHacked (to indicate whether the player is blocked to play the round, as a result of the opponent using a hacking device)

public:
	Player(Cell *pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell *cell); // A setter for the pCell
	Cell *GetCell() const;	  // A getter for the pCell

	void SetHealth(int h); // A setter for the health points
	int GetHealth();	   // A getter for the health points

	/// TODO: You can add setters and getters for data members here (if needed)
	int GetPlayerNum() const;

	// ====== Drawing Functions ======

	void Draw(Output *pOut) const; // Draws the Player's Triangle on its current cell

	void ClearDrawing(Output *pOut) const; // Clears the Player's Triangle from its current cell

	// ====== Game Functions ======

	void Move(Grid *pGrid, Command moveCommands[]); // Moves the Player with the passed move command
													// and Applies the Game Object's effect (if any) of the end reached cell
													// for example, if the end cell contains a belt, take it

	void AppendPlayerInfo(string &playersInfo) const; // Appends player's info to the input string,
													  // for example: P0(Direction, health)
};
