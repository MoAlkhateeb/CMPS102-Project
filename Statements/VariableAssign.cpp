#include "VariableAssign.h"
#include <sstream>

using namespace std;

VariableAssign::VariableAssign(Point Lcorner, string LeftVar, string RightVar)
{

	Type = VAR_ASSIGN;
	LHS = LeftVar;
	RHS = RightVar;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = nullptr;

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;

}

void VariableAssign::setLHS(const string& leftVar) {
	LHS = leftVar;
	UpdateStatementText();
}


void VariableAssign::setRHS(const string& rightVar) {
	RHS = rightVar;
	UpdateStatementText();
}

string VariableAssign::getLHS() const {
	return LHS;
}


string VariableAssign::getRHS() const {
	return RHS;
}


void VariableAssign::Draw(Output* pOut) const
{
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}


//This function should be called when LHS or RHS changes
void VariableAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}

bool VariableAssign::ClickOnStatement(Point click) const
{
	if (click.x < LeftCorner.x || click.x >(LeftCorner.x + UI.ASSGN_WDTH)) return false;
	if (click.y < LeftCorner.y || click.y >(LeftCorner.y + UI.ASSGN_HI)) return false;

	return true;
}

Point VariableAssign::GetFalseOutlet() const {
	return Point(0, 0, false);
}

void VariableAssign::Save(ofstream& OutFile) {
	OutFile << "VAR_ASSIGN" << " " << ID << " " << LeftCorner.x << " " << LeftCorner.y << " " << LHS << " " << RHS << endl;
}