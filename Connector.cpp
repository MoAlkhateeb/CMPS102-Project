#include "Connector.h"
#include <fstream>

Connector::Connector(Statement* Src, Statement* Dst)	
//When a connector is created, it must have a source statement and a destination statement
//There are NO FREE connectors in the flowchart
{
	
	SrcStat = Src;
	DstStat = Dst;
	Selected = false;
}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint(Point P)
{	End = P;	}

Point Connector::getEndPoint()
{	return End;	}

void Connector::Draw(Output* pOut) const
{	
	if (End.y > Start.y) {
		Point yMidPoint(Start.x, (End.y - Start.y)/2 + Start.y);
		pOut->DrawConnector(Start, yMidPoint, Selected);
		Point aboveEnd(End.x, yMidPoint.y);
		pOut->DrawConnector(yMidPoint, aboveEnd, Selected);
		pOut->DrawConnector(aboveEnd, End, Selected);
	}
	else {
		const int dy = 20;
		Point aboveStart(Start.x, End.y - dy);
		pOut->DrawConnector(Start, aboveStart, Selected);
		Point aboveEnd(End.x, End.y - dy);
		pOut->DrawConnector(aboveStart, aboveEnd, Selected);
		pOut->DrawConnector(aboveEnd, End, Selected);
	}

	pOut->DrawArrowHead(End, DOWN, Selected);
}

bool Connector::ClickOnConnector(Point Click) const {
	const int wiggleRoom = 5;

	if (End.y > Start.y) {
		// check first line between start and yMidPoint
		Point yMidPoint(Start.x, (End.y - Start.y) / 2 + Start.y);
		if (Click.y >= Start.y && Click.y <= yMidPoint.y && Click.x >= Start.x - wiggleRoom && Click.x <= Start.x + wiggleRoom) return true;

		Point aboveEnd(End.x, yMidPoint.y);

		if (yMidPoint.x < aboveEnd.x) {
			if (Click.x >= yMidPoint.x && Click.x <= aboveEnd.x && Click.y <= aboveEnd.y + wiggleRoom && Click.y >= aboveEnd.y - wiggleRoom) return true;
		}
		else {
			if (Click.x >= aboveEnd.x && Click.x <= yMidPoint.x && Click.y <= aboveEnd.y + wiggleRoom && Click.y >= aboveEnd.y - wiggleRoom) return true;
		}
		if (Click.y >= aboveEnd.y && Click.y <= End.y && Click.x >= End.x - wiggleRoom && Click.x <= End.x + wiggleRoom) return true;
		return false;
	}
	else {
		const int dy = 20;
		Point aboveStart(Start.x, End.y - dy);
		if (Click.y <= Start.y && Click.y >= aboveStart.y && Click.x >= Start.x - wiggleRoom && Click.x <= Start.x + wiggleRoom) return true;

		Point aboveEnd(End.x, End.y - dy);
		if (aboveStart.x < aboveEnd.x){
			if (Click.x >= aboveStart.x && Click.x <= aboveEnd.x && Click.y <= aboveEnd.y + wiggleRoom && Click.y >= aboveEnd.y - wiggleRoom) return true;
		}
		else {
			if (Click.x >= aboveEnd.x && Click.x <= aboveStart.x && Click.y <= aboveStart.y + wiggleRoom && Click.y >= aboveStart.y - wiggleRoom) return true;
		}
		if (Click.y >= aboveEnd.y && Click.y <= End.y && Click.x >= End.x - wiggleRoom && Click.x <= End.x + wiggleRoom) return true;
		return false;

	}

}

void Connector::SetSelected(bool s)
{
	Selected = s;
}

bool Connector::IsSelected() const
{
	return Selected;
}