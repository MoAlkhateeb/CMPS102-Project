#include "Read.h"

Read::Read(Point LCorner, string text): Statement() {
	pOutConn = nullptr;
	Text = text;
	LeftCorner = LCorner;

	Inlet.x = LeftCorner.x + UI.READ_WDTH / 2;
	Inlet.y = LeftCorner.y - UI.READ_HI;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y;
}

void Read::UpdateStatementText() {}

void Read::Draw(Output* pOut) const {
	pOut->DrawRead(LeftCorner, UI.READ_WDTH, UI.READ_HI, Text, Selected);
}

bool Read::ClickOnStatement(Point click) const {

	if (click.y > LeftCorner.y || click.y < LeftCorner.y - UI.READ_HI) return false;
	if (click.x < LeftCorner.x || click.x > (LeftCorner.x + UI.READ_WDTH)) return false;

	// get parallelogram corners
	Point topLeft;
	Point topRight;
	Point bottomLeft;
	Point bottomRight;

	bottomLeft.x = LeftCorner.x;
	topLeft.x = LeftCorner.x + UI.READ_WDTH / 2;
	topRight.x = LeftCorner.x + UI.READ_WDTH;
	bottomRight.x = LeftCorner.x + UI.READ_WDTH / 2;
	bottomLeft.y = LeftCorner.y;
	topLeft.y = LeftCorner.y + UI.READ_HI / 2;
	topRight.y = LeftCorner.y;
	bottomRight.y = LeftCorner.y - UI.READ_HI / 2;

	
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