#pragma once
#include "Action.h"

class SwitchSimulation : public Action {
public:
	SwitchSimulation(ApplicationManager* pAppManager);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
};