
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Connector.h"
#include "AddConn.h"

AddConn::AddConn(ApplicationManager* pAppManager) : Action(pAppManager){
	Src = nullptr;
	Dst = nullptr;
}
void AddConn::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	Point current;

	pOut->PrintMessage("Click on Source statement.");
	pIn->GetPointClicked(current);
	if (pManager->GetStatement(current)) {
		Src = pManager->GetStatement(current);
		// not a conditional or end statement
		if (Src->getType() != COND && Src->getType() != END) {
			if (Src->GetOutConn()) {
				pOut->PrintMessage("Statement already has an outgoing connector.");
				return;
			}
			Start = Src->GetOutlet();
		}
		// a conditional Statement
		else if (Src->getType() == COND) {
			pOut->PrintMessage("Choose True Outlet or False Outlet. write T or empty for True.");
			string choice = pIn->GetString(pOut);
			if (choice.empty() || tolower(choice[0]) == 't') {
				if (Src->GetOutConn()) {
					pOut->PrintMessage("Statement already has an outgoing connector.");
					return;
				}
				Start = Src->GetOutlet();
			}
			else {
				if (Src->GetFalseOutConn()) {
					pOut->PrintMessage("Statement already has an outgoing connector.");
					return;
				}
				Start = Src->GetFalseOutlet();
			}
		}
		else {
			pOut->PrintMessage("End Statement Doesn't have an outlet.");
			return;
		}
	}
	pOut->PrintMessage("Click on Destination statement.");
	pIn->GetPointClicked(current);
	if (pManager->GetStatement(current)) {
		Dst = pManager->GetStatement(current);
		if (Dst->GetInlet().IsValid()) {
			End = Dst->GetInlet();
		}
		else {
			pOut->PrintMessage("Clicked Statement Doesn't Have an Inlet.");
			Dst = nullptr;
			return;
		}
	}
}
void AddConn::Execute() {
	ReadActionParameters();
	if (!Src || !Dst) {
		return;
	}
	Connector * conn = CreateConnector(Src, Dst, Start, End);
	pManager->AddConnector(conn);
}


Connector* AddConn::CreateConnector(Statement* src, Statement* dst, Point start, Point end) {
	if (!src || !dst) {
		return nullptr;
	}
	Connector* conn = new Connector(src, dst);
	conn->setStartPoint(start);
	conn->setEndPoint(end);

	if (src->getType() != COND) {
		src->setOutConn(conn);
	}
	else if (src->GetOutlet() == start) {
		src->setOutConn(conn);
	}
	else if (src->GetFalseOutlet() == start) {
		src->setFalseOutConn(conn);
	}

	return conn;
}