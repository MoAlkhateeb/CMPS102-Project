#pragma once

#include "Action.h"
#include "../Statements/Statement.h"
#include "../Connector.h"

class Delete : public Action {

private:
	Statement* TargetStatement;
	Connector* TargetConnector;

public:
	Delete(ApplicationManager* pAppManager);

	virtual void ReadActionParameters() override;

	virtual void Execute() override;

};