#pragma once

#include "Action.h"
#include "..\Statements\Write.h"

class AddWrite : public Action
{
private:
	Point Position;
	string Text;

public:
	AddWrite(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters() override;

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() override;

};