#pragma once
#include "Action.h"
#include "../Statements/Statement.h"

class Paste : public Action {
private:
	Statement* TargetStatement;
	Point NewPosition;
public:
	Paste(ApplicationManager* pAppManager);

	virtual void ReadActionParameters() override;
	virtual void Execute() override;
};
