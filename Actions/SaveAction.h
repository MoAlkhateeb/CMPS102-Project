#pragma once
#include "Action.h"

class SaveAction : public Action {
public:
	SaveAction(ApplicationManager* pAppManager);
	virtual void Execute() override;
};