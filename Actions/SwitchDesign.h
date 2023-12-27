#pragma once
#include "Action.h"

class SwitchDesign : public Action {
public:
	SwitchDesign(ApplicationManager* pAppManager);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
};