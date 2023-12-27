
#include "OperatorAssign.h"
#include <sstream>

using namespace std;

OperatorAssign::OperatorAssign(Point Lcorner, const string& LeftHs, const string& RightHs1, const string& RightHs2, const string& Operator) {

	Type = OP_ASSIGN;
	LHS = LeftHs;
	RHS1 = RightHs1;
	RHS2 = RightHs2;
	OP = Operator;
	UpdateStatementText();

	LeftCorner = Lcorner;
	pOutConn = nullptr; // No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}
void OperatorAssign::setLHS(const string& L) {
	LHS = L;
	UpdateStatementText();
}
void OperatorAssign::setRHS1(const string& R1) {
	RHS1 = R1;
	UpdateStatementText();
}
void OperatorAssign::setRHS2(const string& R2) {
	RHS2 = R2;
	UpdateStatementText();
}

string OperatorAssign::getLHS() const {
	return LHS;
}
string OperatorAssign::getRHS1() const {
	return RHS1;
}
string OperatorAssign::getRHS2() const {
	return RHS2;
}
string OperatorAssign::getOP() const {
	return OP;
}

void OperatorAssign::setOperator(const string& Operator) {
	OP = Operator;
	UpdateStatementText();
}

void OperatorAssign::Draw(Output* pOut) const {
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected); 
}

// This function should be called when LHS, RHS1, RHS2, or Operator Changes 
void OperatorAssign::UpdateStatementText() {
	//Left handside then equals the right handside with the operator
	ostringstream T;
	T << LHS << " = " << RHS1 << " " << OP << " " << RHS2;
	Text = T.str();
}

bool OperatorAssign::ClickOnStatement(Point click) const {
	if (click.x < LeftCorner.x || click.x >(LeftCorner.x + UI.ASSGN_WDTH)) return false;
	if (click.y < LeftCorner.y || click.y >(LeftCorner.y + UI.ASSGN_HI)) return false;

	return true;
}

Point OperatorAssign::GetFalseOutlet() const {
	return Point(0, 0, false);
}

void OperatorAssign::Save(ofstream& OutFile) {
	OutFile << "OPER_ASSIGN" << " " << ID << " " << LeftCorner.x << " " << LeftCorner.y << " " << LHS << " " << RHS1 << " " << OP << " " << RHS2 << endl;
}