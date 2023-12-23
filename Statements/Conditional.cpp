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


	// left corner
	TrueOutlet = Lcorner;

	// top corner
	Inlet.x = TrueOutlet.x + UI.CONDITION_WDTH / 2;
	Inlet.y = TrueOutlet.y - UI.CONDITION_HI / 2;

	// right corner
	FalseOutlet.x = TrueOutlet.x + UI.CONDITION_WDTH;
	FalseOutlet.y = TrueOutlet.y;

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
	pOut->DrawConditionalStat(TrueOutlet, UI.CONDITION_WDTH, UI.CONDITION_HI, Text, Selected);
}

bool Conditional::ClickOnStatement(Point click) const {

	Point bottom;
	
	// getting the diamond corners
	
	bottom.x = Inlet.x;
	bottom.y = Inlet.y + UI.CONDITION_HI;
	
	if (click.x < TrueOutlet.x || click.x > FalseOutlet.x) return false;
	if (click.y < Inlet.y || click.y > bottom.y) return false;

	double gradient = (Inlet.y - TrueOutlet.y) / (double)(Inlet.x - TrueOutlet.x);
	
	// top left line
	int y1 = gradient * (click.x - TrueOutlet.x) + TrueOutlet.y;
	
	// bottom left
	int y3 = -gradient * (click.x - TrueOutlet.x) + TrueOutlet.y;

	// top right line
	int y2 = -gradient * (click.x - FalseOutlet.x) + FalseOutlet.y;

	// bottom right
	int y4 = gradient * (click.x - FalseOutlet.x) + FalseOutlet.y;

	if (click.x > Inlet.x && (click.y > y2 && click.y < y4)) return true;
	else if (click.x < Inlet.x && (click.y < y3 && click.y > y1)) return true;


	return false;
}