#include "ValueAssign.h"
#include <sstream>
#include <iostream>
using namespace std;

ValueAssign::ValueAssign(Point Lcorner, string LeftHS, double RightHS) : Statement()
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}

void ValueAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void ValueAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}


void ValueAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}


//This function should be called when LHS or RHS changes
void ValueAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T<<LHS<<" = "<< RHS;	
	Text = T.str();	 
}

bool ValueAssign::ClickOnStatement(Point click) const {
	if (click.x < LeftCorner.x || click.x > (LeftCorner.x + UI.ASSGN_WDTH)) return false;
	if (click.y < LeftCorner.y || click.y > (LeftCorner.y + UI.ASSGN_HI)) return false;
	
	return true;
}

Point ValueAssign::GetInlet() const {
	return Inlet;
}
Point ValueAssign::GetOutlet() const {
	return Outlet;
}
Point ValueAssign::GetFalseOutlet() const {
	return Point(0, 0, false);
}

void ValueAssign::Save(ofstream& OutFile) {
	OutFile << "VAL_ASSIGN" << " " << ID << " " << LeftCorner.x << " " << LeftCorner.y << " " << LHS << " " << RHS << endl;
}