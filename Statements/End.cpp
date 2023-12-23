#include "End.h"

void End::UpdateStatementText() {}

End::End(Point Left) : Statement() {
	pInConn = nullptr;
	LeftCorner = Left;
	Inlet.x = LeftCorner.x + UI.END_WDTH / 2;
	Inlet.y = LeftCorner.y;
}

void End::Draw(Output* pOut) const {
	pOut->DrawEnd(LeftCorner, UI.END_WDTH, UI.END_HI, Selected);
}


bool End::ClickOnStatement(Point click) const {
	Point ellipseCenter; 
	ellipseCenter.x = LeftCorner.x + UI.END_WDTH / 2;
	ellipseCenter.y = LeftCorner.y + UI.END_HI / 2;

	int a = UI.END_WDTH / 2;
	int b = UI.END_HI / 2;

	// expression of ellipse
	double value = pow((click.x - ellipseCenter.x), 2) / pow(a, 2) + pow((click.y - ellipseCenter.y), 2) / pow(b, 2);

	if (value <= 1) return true;
	return false;
}