#include "Conditional.h"
#include <sstream>

void Conditional::UpdateStatementText() {
	ostringstream T;
	T << LHS << " " << OP << " " << RHS;
	Text = T.str();
}


Conditional::Conditional(Point Lcorner, string LeftHS, string Operator, string RightHS): Statement() {
	pOutConn = nullptr;

	LHS = LeftHS;
	RHS = RightHS;
	OP = Operator;

	UpdateStatementText();

	LeftCorner = Lcorner;

	Inlet.x = LeftCorner.x + UI.CONDITION_WDTH / 2;
	Inlet.y = LeftCorner.y - UI.CONDITION_HI / 2;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.CONDITION_HI / 2;

}

void Conditional::setLHS(const string& L) {
	LHS = L;
	UpdateStatementText();
}
void Conditional::setOperator(const string& O) {
	OP = O;
	UpdateStatementText();
}
void Conditional::setRHS(const string& R) {
	RHS = R;
	UpdateStatementText();
}
void Conditional::Draw(Output* pOut) const {
	pOut->DrawConditionalStat(LeftCorner, UI.CONDITION_WDTH, UI.CONDITION_HI, Text, Selected);
}

bool Conditional::ClickOnStatement(Point click) const {

	Point left;
	Point top;
	Point right;
	Point bottom;
	
	// getting the diamond corners
	left.x = LeftCorner.x;
	left.y = LeftCorner.y;
	right.x = left.x + UI.CONDITION_WDTH;
	right.y = left.y;
	top.x = left.x + UI.CONDITION_WDTH / 2;
	top.y = left.y - UI.CONDITION_WDTH / 2;
	bottom.x = top.x;
	bottom.y = top.y - UI.CONDITION_HI;

	// top left line
	int gradient1 = (left.y - top.y) / (left.x - top.x);
	int y1 = gradient1 * click.x + left.y - gradient1 * top.x;

	if (click.y < y1) return false;

	// top right line
	int gradient2 = (right.y - top.y) / (right.x - top.x);
	int y2 = gradient2 * click.x + right.y - gradient2 * top.x;

	if (click.y < y2) return false;

	// bottom left
	int gradient3 = (left.y - bottom.y) / (left.x - bottom.x);
	int y3 = gradient3 * click.x + left.y - gradient3 * bottom.x;

	if (click.y > y3) return false;

	// bottom right
	int gradient4 = (right.y - bottom.y) / (right.x - bottom.x);
	int y4 = gradient4 * click.x + right.y - gradient4 * bottom.x;

	if (click.y > y4) return false;


	return true;
}