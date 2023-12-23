
#include "AddConditional.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConditional::AddConditional(ApplicationManager* pAppManager) : Action(pAppManager)
{}

void AddConditional::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Conditional Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	OpType LHStype;
	string possibleLHS;

	OpType RHStype;
	string possibleRHS;

	while (true) {
		do {
			pOut->PrintMessage("Enter a value of variable for the LHS: ");
			possibleLHS = pIn->GetString(pOut);
			LHStype = ValueOrVariable(possibleLHS);
		} while (LHStype == INVALID_OP);

		do {
			pOut->PrintMessage("Enter a value or variable for the RHS: ");
			possibleRHS = pIn->GetString(pOut);
			RHStype = ValueOrVariable(possibleRHS);
		} while (RHStype == INVALID_OP);

		if (LHStype == VALUE_OP && RHStype == VALUE_OP) 
			continue;

		break;
	}

	OP = pIn->GetCompOperator(pOut);
	RHS = possibleRHS;
	LHS = possibleLHS;

	pOut->ClearStatusBar();
}

void AddConditional::Execute()
{
	ReadActionParameters();

	Point Corner;
	Corner.x = Position.x - UI.CONDITION_WDTH / 2;
	Corner.y = Position.y - UI.CONDITION_HI / 2;

	Conditional* pCond = new Conditional(Corner, LHS, OP, RHS);

	pManager->AddStatement(pCond); // Adds the created statement to application manger's statement list
}

