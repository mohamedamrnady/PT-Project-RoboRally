#include "WorkshopItem.h"

WorkshopItem::WorkshopItem(int c) : cost(c)
{
	// The constructor initializes the ApplicationManager pointer data member
}

int WorkshopItem::GetCost() const
{
	return cost;
}

WorkshopItem::~WorkshopItem()
{
}
