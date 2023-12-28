#include "Start.h"

void Start::UpdateStatementText() {}

Start::Start(Point Left) : Statement() {
	Type = START;
	LeftCorner = Left;
	Outlet.x = LeftCorner.x + UI.START_WDTH / 2;
	Outlet.y = LeftCorner.y + UI.START_HI;
}

void Start::Draw(Output* pOut) const {
	pOut->DrawStart(LeftCorner, UI.START_WDTH, UI.START_HI, Selected);
}

bool Start::ClickOnStatement(Point click) const {
	Point ellipseCenter;
	ellipseCenter.x = LeftCorner.x + UI.START_WDTH / 2;
	ellipseCenter.y = LeftCorner.y + UI.START_HI / 2;

	int a = UI.START_WDTH / 2;
	int b = UI.START_HI / 2;

	// expression of ellipse
	double value = pow((click.x - ellipseCenter.x), 2) / pow(a, 2) + pow((click.y - ellipseCenter.y), 2) / pow(b, 2);

	if (value <= 1) return true;
	return false;
}

Point Start::GetInlet() const {
	return Point(0, 0, false);
}
Point Start::GetFalseOutlet() const {
	return Point(0, 0, false);
}

void Start::Save(ofstream& OutFile) {
	OutFile << "START" << " " << ID << " " << LeftCorner.x << " " << LeftCorner.y << endl;
}

Start* Start::Load(ifstream& InFile) {
	int ID;
	Point topLeftCorner;

	InFile >> ID >> topLeftCorner.x >> topLeftCorner.y;
	Start* StartPtr = new Start(topLeftCorner);

	return StartPtr;
}