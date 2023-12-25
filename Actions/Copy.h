#pragma once

#include "Action.h"
#include "../Statements/Statement.h"

class Copy :public Action {
private:
	Statement* TargetStatment; // Statement to be Copied
public:
	Copy(ApplicationManager* pAppManager);

	virtual void ReadActionParameters() override;

	virtual void Execute() override;
};