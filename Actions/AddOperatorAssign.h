#pragma once
#include "Action.h"
#include <string>

//Add Operator Assignment Statement Action
//This class is responsible for 
// 1 - Getting Assignment stat. coordinates from the user (one of the parameters of this action)
// 2 - Getting the LHS and RHS of the statement from the user (some of the parameters of this action)
// 3 - Creating an object of Assignment class and passing it parameters
// 4 - Adding the created object to the list of statements of the application manager

class AddOperatorAssign :public Action {
private:
	Point Position;
	string LHS;
	string OP;
	string RHS1;
	string RHS2;

public:
	AddOperatorAssign(ApplicationManager* pAppManager);

	// Read Assignment statment's position, LHS, Operator, and RHS
	virtual void ReadActionParameters() override;

	// Create and add an operator assignment statement to the list of statements
	virtual void Execute() override;
};