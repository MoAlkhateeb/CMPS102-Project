#pragma once

#include "Action.h"
#include "..\Statements\End.h"

class AddEnd : public Action
{
private:
	Point Position;

public:
	AddEnd(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters() override;

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() override;

};