
#include "AddOperatorAssign.h"
#include "../Statements/OperatorAssign.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

#include <sstream>

using namespace std;

// Constructor: set the application manager pointer inside the action

AddOperatorAssign::AddOperatorAssign(ApplicationManager* pAppManager) :Action(pAppManager) {}

void AddOperatorAssign::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Operator Assignment Statement: Click to add the statement");
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	//Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Enter the Left-Hand Side (variable name): ");
	LHS = pIn->GetVariable(pOut);
	pOut->ClearStatusBar();

	// Ask the user in the status bar to enter the RHS and set the data member

	string input;
	do {
		pOut->PrintMessage("Enter the first operand of the RHS: ");
		input = pIn->GetString(pOut);
		pOut->ClearStatusBar();
	} while (ValueOrVariable(input) == INVALID_OP);

	RHS1 = input;
	
	pOut->PrintMessage("Enter the Operator (+,-,*,/): ");
	OP = pIn->GetArithOperator(pOut);
	pOut->ClearStatusBar();


	do {
		pOut->PrintMessage("Enter the second operand of the RHS: ");
		input = pIn->GetString(pOut);
		pOut->ClearStatusBar();
	} while (ValueOrVariable(input) == INVALID_OP);

	RHS2 = input;
}

void AddOperatorAssign::Execute() {
	ReadActionParameters();
	Point Corner;
	// Calculate the left corner of the assignment statmenet block;

	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	OperatorAssign* pAssign = new OperatorAssign(Corner, LHS, RHS1, RHS2, OP);

	pManager->AddStatement(pAssign);
}