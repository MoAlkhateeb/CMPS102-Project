#pragma once
#include "Action.h"

class Validate : public Action {
public:
	Validate(ApplicationManager* pAppManager);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
};