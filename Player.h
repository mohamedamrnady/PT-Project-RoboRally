#pragma once

#include "Grid.h"
#include "Cell.h"
#include "WorkshopItem.h"

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
	WorkshopItemTypes *purchasedItems;
	// carried laser type (default, double laser)
	string laserType;

	// isHacked (to indicate whether the player is blocked to play the round, as a result of the opponent using a hacking device)
	bool isHacked;
	Command *SavedCommand; // array of the commands the playes has chosed
	int NumOfSavedCommands;
	Workshop *pWorkshop;

public:
	Player(Cell *pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell *cell); // A setter for the pCell
	Cell *GetCell() const;	  // A getter for the pCell

	bool SetHealth(int h, Grid *pGrid); // A setter for the health points
	int GetHealth();					// A getter for the health points

	Direction getDirection();
	void setDirection(Direction dir);

	void SetSavedCommands(Command array[]);

	/// TODO: You can add setters and getters for data members here (if needed)
	int GetPlayerNum() const;
	int GetNumOfSavedCommands() const;
	void SetNumOfSavedCommands(int num);

	// Setters
	void AddItem(WorkshopItemTypes item);
	WorkshopItemTypes *GetItems() const;
	void SetWorkshop(Workshop *workshop);
	Workshop *GetWorkshop() const;
	void UpgradeLaserType();
	string getLaserType() const;
	void SetIsHacked(bool hacked);
	bool GetIsHacked() const;

	// // Getters
	// int getEquipments() const;
	// bool getHaveConsumables() const;
	// string getLaserType() const;

	// ====== Drawing Functions ======

	void Draw(Output *pOut) const; // Draws the Player's Triangle on its current cell

	void ClearDrawing(Output *pOut) const; // Clears the Player's Triangle from its current cell

	// ====== Game Functions ======

	Command *GetSavedCommands();

	void Move(Grid *pGrid, Command moveCommands[]); // Moves the Player with the passed move command
													// and Applies the Game Object's effect (if any) of the end reached cell
													// for example, if the end cell contains a belt, take it

	void AppendPlayerInfo(string &playersInfo) const; // Appends player's info to the input string,
													  // for example: P0(Direction, health)
};
