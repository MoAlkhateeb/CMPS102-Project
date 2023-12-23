#pragma once

#include "Action.h"
#include "..\Statements\Read.h"

class AddRead : public Action
{
private:
	Point Position;
	string Text;

public:
	AddRead(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters() override;

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() override;

};