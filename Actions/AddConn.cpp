
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
		if (Src->GetOutlet().IsValid() && !Src->GetFalseOutlet().IsValid()) {
			Start = Src->GetOutlet();
		}
		// a conditional Statement
		else if (Src->GetOutlet().IsValid() && Src->GetFalseOutlet().IsValid()) {
			pOut->PrintMessage("Choose True Outlet or False Outlet. write T or empty for True.");
			string choice = pIn->GetString(pOut);
			if (choice.empty() || tolower(choice[0]) == 't') {
				Start = Src->GetOutlet();
			}
			else {
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

	Connector* conn = new Connector(Src, Dst);
	conn->setStartPoint(Start);
	conn->setEndPoint(End);
	pManager->AddConnector(conn);

}
