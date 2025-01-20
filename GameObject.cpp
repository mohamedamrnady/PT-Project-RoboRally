#include "GameObject.h"

GameObject::GameObject(const CellPosition &pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject *GameObject::GetObjPosition(const CellPosition &pos)
{
	if (position.GetCellNum() == pos.GetCellNum())
		return this;
	else
		return nullptr;
}

GameObject::~GameObject()
{
}