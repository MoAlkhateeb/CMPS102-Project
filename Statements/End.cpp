#include "End.h"

void End::UpdateStatementText() {}

End::End(Point Left) : Statement() {
	Type = END;
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

Point End::GetOutlet() const {
	return Point(0, 0, false);
}

Point End::GetFalseOutlet() const {
	return Point(0, 0, false);
}

void End::Save(ofstream& OutFile) {
	OutFile << "END" << " " << ID << " " << LeftCorner.x << " " << LeftCorner.y  << endl;
}

End* End::Load(ifstream& InFile) {
	int ID;
	Point left;

	InFile >> ID >> left.x >> left.y;

	End* EndPtr = new End(left);
	return EndPtr;
}