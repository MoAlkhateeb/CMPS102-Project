#include "Write.h"

Write::Write(Point LCorner, string text) : Statement() {
	pOutConn = nullptr;
	Text = text;
	LeftCorner = LCorner;
	Inlet.x = LeftCorner.x + UI.WRITE_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.WRITE_HI;
}

void Write::UpdateStatementText() {}

void Write::Draw(Output* pOut) const {
	pOut->DrawRead(LeftCorner, UI.WRITE_WDTH, UI.WRITE_HI, Text, Selected);
}


bool Write::ClickOnStatement(Point click) const {

	if (click.y > LeftCorner.y || click.y < LeftCorner.y - UI.WRITE_HI) return false;
	if (click.x < LeftCorner.x || click.x >(LeftCorner.x + UI.WRITE_WDTH)) return false;

	// get parallelogram corners
	Point topLeft;
	Point topRight;
	Point bottomLeft;
	Point bottomRight;

	bottomLeft.x = LeftCorner.x;
	topLeft.x = LeftCorner.x + UI.WRITE_WDTH / 2;
	topRight.x = LeftCorner.x + UI.WRITE_WDTH;
	bottomRight.x = LeftCorner.x + UI.WRITE_WDTH / 2;
	bottomLeft.y = LeftCorner.y;
	topLeft.y = LeftCorner.y + UI.WRITE_HI / 2;
	topRight.y = LeftCorner.y;
	bottomRight.y = LeftCorner.y - UI.WRITE_HI / 2;


	// left line
	int gradient1 = (topLeft.y - bottomLeft.y) / (topLeft.x - bottomLeft.x);
	int y1 = gradient1 * click.x + topLeft.y - gradient1 * topLeft.x;

	if (click.y < y1) return false;

	// right line
	int gradient2 = (topRight.y - bottomRight.y) / (topRight.x - bottomRight.x);
	int y2 = gradient2 * click.x + topRight.y - gradient2 * topRight.x;

	if (click.y > y1) return false;

	return true;
}