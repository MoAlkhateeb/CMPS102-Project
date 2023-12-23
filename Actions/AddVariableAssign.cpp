
#include "AddVariableAssign.h"
#include "../Statements/VariableAssign.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

#include <sstream>

using namespace std;

AddVariableAssign::AddVariableAssign(ApplicationManager* pAppManager) :Action(pAppManager) {}

void AddVariableAssign::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Variable Assignment Statement: Click to add the statement");
	pIn->GetPointClicked(Position);

	//Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Enter the Left-Hand Side (variable name): ");
	LHS = pIn->GetVariable(pOut);

	// Ask the user in the status bar to enter the RHS and set the data member
	pOut->PrintMessage("Enter the Right-Hand (variable name): ");
	RHS = pIn->GetVariable(pOut);
	pOut->ClearStatusBar();
}
void AddVariableAssign::Execute() {
	ReadActionParameters();

	// Calculationg Left corner of assignment statment block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	VariableAssign* pAssign = new VariableAssign(Corner, LHS, RHS);

	pManager->AddStatement(pAssign); //Adds the created statement to the application manager statement list
}