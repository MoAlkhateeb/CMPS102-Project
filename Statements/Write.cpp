#include "Write.h"

Write::Write(Point LCorner, string text) : Statement() {

	Type = WRITE;
	pOutConn = nullptr;
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

void Write::UpdateStatementText() {}

void Write::Draw(Output* pOut) const {
	pOut->DrawWrite(bottomLeft, UI.WRITE_WDTH, UI.WRITE_HI, Text, Selected);
}

bool Write::ClickOnStatement(Point click) const {

	if (click.y > bottomLeft.y || click.y < topRight.y) return false;
	if (click.x < bottomLeft.x || click.x > topRight.x) return false;

	// left line
	double gradient = (topLeft.y - bottomLeft.y) / (double) (topLeft.x - bottomLeft.x);
	double y1 = gradient * click.x + topLeft.y - gradient * topLeft.x;

	if (click.y < y1) return false;

	// right line
	double y2 = gradient * click.x + topRight.y - gradient * topRight.x;

	if (click.y > y2) return false;

	return true;
}

Point Write::GetFalseOutlet() const {
	return Point(0, 0, false);
}

void Write::Save(ofstream& OutFile) {
	OutFile << "WRITE" << " " << ID << " " << bottomLeft.x << " " << bottomLeft.y << " " << Text << " " << endl;
}