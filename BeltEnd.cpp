#include "BeltEnd.h"
#include "Player.h"

BeltEnd::BeltEnd(const CellPosition &beltEndPosition) : GameObject(beltEndPosition)
{
}

void BeltEnd::Draw(Output *pOut) const
{
}

void BeltEnd::Apply(Grid *pGrid, Player *pPlayer)
{
}

void BeltEnd::Save(ofstream &OutFile, int t)
{
}

int BeltEnd::GetObjType()
{
    return belt_end;
}

void BeltEnd::Load(ifstream &Infile)
{
    int startcellnum, endcellnum;
    Infile >> startcellnum;
    Infile >> endcellnum;
    position.SetCellNum(endcellnum);
}

GameObject *BeltEnd::clone() const
{
    return new BeltEnd(*this);
}

BeltEnd::~BeltEnd()
{
}
