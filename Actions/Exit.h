#pragma once

#include "Action.h"

class Exit : public Action {

public:
	Exit(ApplicationManager* pAppManager);

	virtual void ReadActionParameters() override;

	virtual void Execute() override;

};