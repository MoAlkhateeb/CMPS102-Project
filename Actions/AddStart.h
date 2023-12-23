#pragma once

#include "Action.h"
#include "..\Statements\Start.h"

class AddStart : public Action
{
private:
	Point Position;

public:
	AddStart(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters() override;

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() override;

};