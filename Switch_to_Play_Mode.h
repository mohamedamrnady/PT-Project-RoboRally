#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include <fstream>
#include "Grid.h"

//3yzeen n3mel 7etet el save 3shan ysayev f folder

class Switch_to_Play_Mode :
    public Action
{
public:
	Switch_to_Play_Mode(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~Switch_to_Play_Mode();


};

