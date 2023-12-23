#pragma once
#include "Action.h"
#include "../Statements/Statement.h"
#include "../Connector.h"

class SelectDeselect : public Action
{
private:
	Point Position;
	Statement* TargetStatement;
	Connector* TargetConnector;

public:
	SelectDeselect(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters() override;

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() override;

};