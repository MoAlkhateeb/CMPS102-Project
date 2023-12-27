#include "Conditional.h"
#include <sstream>

void Conditional::UpdateStatementText() {
	ostringstream T;
	T << LHS << " " << OP << " " << RHS;
	Text = T.str();
}


Conditional::Conditional(Point Lcorner, string LeftHS, string Operator, string RightHS): Statement() {
	Type = COND;
	pOutConn = nullptr;

	LHS = LeftHS;
	RHS = RightHS;
	OP = Operator;

	UpdateStatementText();


	// left corner
	Outlet = Lcorner;

	// top corner
	Inlet.x = Outlet.x + UI.CONDITION_WDTH / 2;
	Inlet.y = Outlet.y - UI.CONDITION_HI / 2;

	// right corner
	FalseOutlet.x = Outlet.x + UI.CONDITION_WDTH;
	FalseOutlet.y = Outlet.y;

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
	pOut->DrawConditionalStat(Outlet, UI.CONDITION_WDTH, UI.CONDITION_HI, Text, Selected);
}

bool Conditional::ClickOnStatement(Point click) const {

	Point bottom;
	
	// getting the diamond corners
	
	bottom.x = Inlet.x;
	bottom.y = Inlet.y + UI.CONDITION_HI;
	
	if (click.x < Outlet.x || click.x > FalseOutlet.x) return false;
	if (click.y < Inlet.y || click.y > bottom.y) return false;

	double gradient = (Inlet.y - Outlet.y) / (double)(Inlet.x - Outlet.x);
	
	// top left line
	int y1 = gradient * (click.x - Outlet.x) + Outlet.y;
	
	// bottom left
	int y3 = -gradient * (click.x - Outlet.x) + Outlet.y;

	// top right line
	int y2 = -gradient * (click.x - FalseOutlet.x) + FalseOutlet.y;

	// bottom right
	int y4 = gradient * (click.x - FalseOutlet.x) + FalseOutlet.y;

	if (click.x > Inlet.x && (click.y > y2 && click.y < y4)) return true;
	else if (click.x < Inlet.x && (click.y < y3 && click.y > y1)) return true;


	return false;
}

void Conditional::Save(ofstream& OutFile) {
	OutFile << "COND" << " " << ID << " " << Outlet.x << " " << Outlet.y  << " " << LHS << " " << OP << " " << RHS << endl;
}