#include "Read.h"

Read::Read(Point LCorner, string text): Statement() {
	Type = READ;
	Text = text;

	bottomLeft = LCorner;

	topLeft.x = bottomLeft.x + UI.WRITE_WDTH / 4;
	topLeft.y = bottomLeft.y - UI.WRITE_HI;
	topRight.x = bottomLeft.x + UI.WRITE_WDTH + UI.WRITE_WDTH / 4;
	topRight.y = topLeft.y;
	bottomRight.x = bottomLeft.x + UI.WRITE_WDTH;
	bottomRight.y = bottomLeft.y;

	Inlet.x = topLeft.x + UI.WRITE_WDTH / 2;
	Inlet.y = topLeft.y;

	Outlet.x = Inlet.x;
	Outlet.y = bottomLeft.y;
}

void Read::UpdateStatementText() {}

void Read::Draw(Output* pOut) const {
	pOut->DrawRead(bottomLeft, UI.READ_WDTH, UI.READ_HI, Text, Selected);
}

bool Read::ClickOnStatement(Point click) const {

	if (click.y > bottomLeft.y || click.y < topRight.y) return false;
	if (click.x < bottomLeft.x || click.x > topRight.x) return false;

	// left line
	double gradient = (topLeft.y - bottomLeft.y) / (double)(topLeft.x - bottomLeft.x);
	double y1 = gradient * click.x + topLeft.y - gradient * topLeft.x;

	if (click.y < y1) return false;

	// right line
	double y2 = gradient * click.x + topRight.y - gradient * topRight.x;

	if (click.y > y2) return false;

	return true;
}

Point Read::GetFalseOutlet() const {
	return Point(0, 0, false);
}

void Read::Save(ofstream& OutFile) {
	OutFile << "READ" << " " << ID << " " << bottomLeft.x << " " << bottomLeft.y << " " << Text << endl;
}

Read* Read::Load(ifstream& InFile) {
	int ID, x, y;
	string Var;

	InFile >> ID >> x >> y >> Var;
	Read* ReadPtr = new Read(Point(x, y), Var);

	return ReadPtr;
}