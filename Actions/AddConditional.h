#pragma once

#include "Action.h"
#include "..\Statements\Conditional.h"


class AddConditional : public Action
{
private:
	Point Position;
	string LHS;
	string OP;
	string RHS;

public:
	AddConditional(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters() override;

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() override;

};