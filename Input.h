#ifndef INPUT_H
#define INPUT_H

#include "DEFS.h"
#include "UI_Info.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CellPosition.h"

// forward declarations (their includes are in the cpp)
class Output;

class Input // The application manager & grid (phase 2) should have a pointer to this class
{
private:
	window *pWind; // Pointer to the Graphics Windo

public:
	// ========== General Functions ==========

	Input(window *pW); // Consturctor: Points to the passed window pointer

	void GetPointClicked(int &x, int &y) const; // Wait for a Mouse Click and Gets the real coordinates (x,y) of it

	string GetSrting(Output *pO) const; // Returns a string entered by the user

	/// TODO: IMPLEMENT THE FOLLOWING FUNCTION
	int GetInteger(Output *pO) const; // Returns an integer entered by the user

	// ========== Game Functions ==========

	/// TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	// Reads a user click and map it to its corresponding ActionType
	ActionType GetUserAction() const;

	/// TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	CellPosition GetCellClicked() const; // Wait for a Mouse Click and Gets the CellPosition of it (VCell and HCell)
										 // This function is needed only in Design Mode
										 // If the click is NOT on a cellposition, (-1,-1) is returned
										 // This function is like GetPointClicked but returns Cell Position NOT Real Coordinates

	// In the play mode, Wait for the user to select a command from the available commands
	// shown in the commands bar and return the clicked command index (0 is the first command, 1 is the second, and so on)
	// will return -1 if the click was NOT on one of the commands
	int GetSelectedCommandIndex() const;
};

#endif