#include "RebootandRepair.h"

RebootandRepair::RebootandRepair(ApplicationManager *pApp) : Action(pApp)
{
}

void RebootandRepair::ReadActionParameters()
{
}

void RebootandRepair::Execute()
{
    pPlayer = pManager->GetGrid()->GetCurrentPlayer();
    pPlayer->SetHealth(10);
}

RebootandRepair::~RebootandRepair()
{
}