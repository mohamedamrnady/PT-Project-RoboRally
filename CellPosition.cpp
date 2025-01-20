#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}
//////////////////////////////////////////////////////////////////////////////////
CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
											   // from the passed (cellNum)
											   // (*this) = ... --> this will copy the returned (vCell and hCell)
											   //                   to the data members (vCell and hCell)
}
// like a getter

bool CellPosition::SetVCell(int v)
{
	if (v < NumVerticalCells && v >= 0)
	{
		vCell = v;
		return true;
	}
	else
	{
		return false;
	}
}
// Done //NumVeriticale cells

bool CellPosition::SetHCell(int h)
{
	/// DONE: Implement this function as described in the .h file (don't forget the validation)
	if (h < NumHorizontalCells && h >= 0)
	{
		hCell = h;
		return true;
	}
	else
	{
		return false;
	}
}
// done

int CellPosition::VCell() const
{
	return vCell;
}
int CellPosition::HCell() const
{
	return hCell;
}
// getters

bool CellPosition::IsValidCell() const
{
	/// DONE: Implement this function as described in the .h file
	return ((vCell < NumVerticalCells && vCell >= 0) && (hCell < NumHorizontalCells && hCell >= 0));
}
// done

int CellPosition::GetCellNum() const
{

	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum									  // which means the object of the current data members (vCell and hCell)
}
// done

int CellPosition::GetCellNumFromPosition(const CellPosition &cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	/// DONE: Implement this function as described in the .h file

	int v = cellPosition.VCell();
	int h = cellPosition.HCell();
	int cellNumber = (45 - (v * 11) + h);
	// v =3 h =4
	//  (45 - (3*11) + 4) = 16

	return cellNumber;
}
// done

CellPosition CellPosition::GetCellPositionFromNum(int cellNum) // return and position cell object
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	int v = -1;
	int h = -1;
	if (cellNum <= 11 && cellNum >= 1)
	{
		v = 4;
		h = cellNum - 1;
	}
	else if (cellNum >= 12 && cellNum <= 22)
	{
		v = 3;
		h = cellNum - 12;
	}
	else if (cellNum >= 23 && cellNum <= 33)
	{
		v = 2;
		h = cellNum - 23;
	}
	else if (cellNum >= 34 && cellNum <= 44)
	{
		v = 1;
		h = cellNum - 34;
	}
	else if (cellNum >= 45 && cellNum <= 55)
	{
		v = 0;
		h = cellNum - 45;
	}

	//	h = cellNum - 1 - 11 * v;
	// 28    w el v=2      // -> h=cellNum-1 -11*v
	position.SetHCell(h);
	position.SetVCell(v);

	return position;
}
// done

void CellPosition::AddCellNum(int addedNum, Direction direction)
{
	int cell = 0;

	switch (direction)
	{
	case UP:
		if (SetVCell(VCell() - addedNum))
			cell = 0;
		else
			SetVCell(0);
		break;

	case DOWN:

		if (SetVCell(VCell() + addedNum))
			cell = 0;
		else
			SetVCell(4);
		break;

	case RIGHT:
		if (SetHCell(HCell() + addedNum))
			cell = 0;
		else
			SetHCell(10);
		break;

	case LEFT:
		if (SetHCell(HCell() - addedNum))
			cell = 0;
		else
			SetHCell(0);
		break;
	}
}
// done

void CellPosition::SetCellNum(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum);
}
