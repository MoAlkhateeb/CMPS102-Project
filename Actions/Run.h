#pragma once

#include "Action.h"
#include "../Statements/Statement.h"

class Run :public Action {
private:
	bool valid;
public:
	Run(ApplicationManager* pAppManager);

	virtual void ReadActionParameters() override;

	virtual void Execute() override;
};