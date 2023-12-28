#pragma once
#include "Action.h"

class LoadAction : public Action {
private:
	string filename;
public:
	LoadAction(ApplicationManager* pAppManager);
	virtual void Execute() override;
	virtual void ReadActionParameters();
};