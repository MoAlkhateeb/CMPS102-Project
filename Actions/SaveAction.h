#pragma once
#include "Action.h"

class SaveAction : public Action {

private:
	string filename;

public:
	SaveAction(ApplicationManager* pAppManager);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
};