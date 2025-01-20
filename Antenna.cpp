#include "Antenna.h"
#include "Player.h"

Antenna::Antenna(const CellPosition &antennaPosition) : GameObject(antennaPosition)
{
}

void Antenna::Draw(Output *pOut) const
{
	pOut->DrawAntenna(position);
}

void Antenna::Apply(Grid *pGrid, Player *pPlayer)
{

	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "the antenna will decide the turn of players. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("The antenna will decide the turn of players. Click to continue ...");
	// 2- Apply the antenna effect by following these notes,
	// check grid class and decide which function to use
	// The antenna determines the turn order for players.
	// The distance of each player from the antenna determines his turn order in each rount.
	// Player with the minimum distance[ from the antenna will have the first turn in that round.
	// If there is a tie, player number will break it, for example if player 1 & 2 are in the same cell and they have the same distance from the antenna, player 1 will play first in that round.
	int distances[MaxPlayerCount];
	int closestPlayer;
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		Player *player = pGrid->GetCurrentPlayer();
		// get move vector from player to antenna
		CellPosition antennaPos = this->GetPosition();
		CellPosition playerPos = player->GetCell()->GetCellPosition();
		int distanceH = antennaPos.HCell() - playerPos.HCell();
		int distanceV = antennaPos.VCell() - playerPos.VCell();
		distances[player->GetPlayerNum()] = sqrt(distanceH * distanceH + distanceV * distanceV);
		// check closest player
		if (i == 0)
		{
			closestPlayer = player->GetPlayerNum();
		}
		else
		{
			if (distances[player->GetPlayerNum()] < distances[closestPlayer])
			{
				closestPlayer = player->GetPlayerNum();
			}
			else if (distances[player->GetPlayerNum()] == distances[closestPlayer])
			{
				if (player->GetPlayerNum() < closestPlayer)
				{
					closestPlayer = player->GetPlayerNum();
				}
			}
		}
		pGrid->AdvanceCurrentPlayer();
	}
	// set current player to the closest player
	pGrid->SetCurrentPlayer(closestPlayer);

	// 3- After deciding the turn of player Print a message indicating which player will play first example: "Player 1 will play first"
	string message = "Player " + std::to_string(closestPlayer) + " will play first";
	pGrid->PrintErrorMessage(message);
}

void Antenna::Save(ofstream &OutFile, int t)
{
	if (t == antenna)
	{
		int cellnum = position.GetCellNum();
		OutFile << cellnum << endl;
	}
}

int Antenna::GetObjType()
{
	return antenna;
}

void Antenna::Load(ifstream &Infile)
{
	int cellnum;
	Infile >> cellnum;
	position.SetCellNum(cellnum);
}
GameObject *Antenna::clone() const
{
	return new Antenna(*this);
}

Antenna::~Antenna()
{
}
