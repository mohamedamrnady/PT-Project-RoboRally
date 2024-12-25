#ifndef OUPTUT_H
#define OUPTUT_H

#include "DEFS.h"
#include "UI_Info.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CellPosition.h"

// forward declarations (their includes are in the cpp)
class Input;

class Output // The application manager & grid (phase 2) should have a pointer to this class
{
private:
	window *pWind; // Pointer to the Graphics Window

	// ========== Some Utility Functions (Private Functions) ==========

	/// TODO: IMPLEMENT THE FOLLOWING FUNCTION
	// Gets the X coordinate of the upper left corner of the passed cellpos
	int GetCellStartX(const CellPosition &cellpos) const;

	/// TODO: IMPLEMENT THE FOLLOWING FUNCTION
	// Gets the Y coordinate of the upper left corner of the passed cellpos
	int GetCellStartY(const CellPosition &cellpos) const;

	// A helper function to draw a triangle with a certain color given its center, height, width, and direction
	void Output::DrawTriangle(int triangleCenterX, int triangleCenterY,
							  int triangleHeight, int triangleWidth,
							  Direction direction, color triangleColor,
							  drawstyle style = FILLED, int penWidth = 1) const;

	// A helper function to draw an image in the center of a cell
	void Output::DrawImageInCell(const CellPosition &cellPos, string image, int width, int height) const;

	void ClearToolBar() const; // Clears the toolbar by drawing a filled rectangle

	// Draws the saved commands in the commands bar during the play mode
	void DrawSavedCommands(Command savedCommands[], int savedCommandsCount, string CommandItemImages[]) const;
	// Draws the available commands in the commands bar during the play mode
	void DrawAvailableCommands(Command availableCommands[], int availableCommandsCount, string CommandItemImages[]) const;

public:
	Output(); // A Constructor for any needed initializations

	window *CreateWind(int, int, int, int) const; // Creates the application window

	Input *CreateInput() const; // Creates a pointer to the Input object

	// ========== User Interface Functions ==========

	void ClearStatusBar() const;   // Clears the status bar by drawing a filled rectangle
	void ClearCommandsBar() const; // Clears the Commands bar by drawing a filled rectangle
	void ClearGridArea() const;	   // Draws an empty grid (horizontal and vertical lines with empty cells)

	/// TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	void CreateDesignModeToolBar() const; // Creates the Design mode toolbar with all its menu icons

	/// TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	void CreatePlayModeToolBar() const; // Creates the Play mode toolbar with all its menu icons

	void CreateCommandsBar(Command savedCommands[], int savedCommandsCount, Command availableCommands[], int availableCommandsCount) const;

	void PrintMessage(string msg) const; // Prints a message on Status bar

	/// TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	void PrintPlayersInfo(string info); // Prints players' info on the right-side of the toolbar

	// ========== Game Drawing Functions ==========

	/// TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	// Draws "Cell Rectangle" with "Cell Number"
	// the cell rectangle's color is cellColor
	void DrawCell(const CellPosition &cellpos, color cellColor = UI.CellColor) const;

	/// TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	// Draws "Player Triangle" filled with the passed color
	//	"playerNum" parameter is used for locating the triangle
	//	** Players' Triangle Locations depending on "playerNum" is as follows: **
	//	Player_0
	//	Player_1
	void DrawPlayer(const CellPosition &cellpos, int playerNum, color playerColor, Direction direction) const;

	// TODO: Complete the implementation of the following function
	// Draws a belt from start cell to end cell (start < end)
	// Belt is drawn as a line from the start cell to the end cell
	//		with a triangle at the middle of the line pointing to the end cell and showing the direction
	// Don't forget any needed validations on fromCellPos and toCellPos
	void DrawBelt(const CellPosition &fromCellPos, const CellPosition &toCellPos) const;

	// TODO: Complete the implementation of the following function
	// Draws a Flag at the passed cell position
	// Flag is drawn as a triangle pointing to the right
	// and its post is a vertical line
	void DrawFlag(const CellPosition &cellPos) const;

	// TODO: Complete the implementation of the following function
	// Draws an image indicating a rotating gear at the passed cell position
	// make sure to draw the gear with the correct rotation
	void DrawRotatingGear(const CellPosition &cellPos, bool clockwise) const;

	// TODO: Complete the implementation of the following function
	// Draws an image indicating a workshop at the passed cell position
	void DrawWorkshop(const CellPosition &cellPos) const;

	// TODO: Complete the implementation of the following function
	// Draws an image indicating an antenna at the passed cell position
	void DrawAntenna(const CellPosition &cellPos) const;

	// TODO: Complete the implementation of the following function
	// Change the passed cell to make it appears a Danger Zone as specified in the document
	void DrawDangerZone(const CellPosition &cellPos) const;

	// TODO: Complete the implementation of the following function
	// Change the passed cell to make it appears a Water Pit as specified in the document
	void DrawWaterPit(const CellPosition &cellPos) const;

	~Output(); // A Destructor for any needed deallocations
};

#endif