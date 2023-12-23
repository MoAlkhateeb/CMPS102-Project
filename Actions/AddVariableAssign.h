#pragma once
#include "Action.h"


class AddVariableAssign : public Action {
private:
	Point Position;
	string LHS;
	string RHS;
	
public:
	AddVariableAssign(ApplicationManager* pAppManager);

	//Read Assignment statements's position, LHS and RHS
	virtual void ReadActionParameters() override;

	//create and add a variable assignment statement to the list of the statements 
	virtual void Execute() override;
};