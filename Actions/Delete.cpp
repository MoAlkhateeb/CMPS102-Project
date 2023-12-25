#include "delete.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


Delete::Delete(ApplicationManager* pAppManager) : Action(pAppManager) {
	TargetConnector = nullptr;
	TargetStatement = nullptr;
}


void Delete::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();

	if (pManager->GetSelectedConnector()) {
		TargetConnector = pManager->GetSelectedConnector();
	}
	
	if (pManager->GetSelectedStatement()) {
		TargetStatement = pManager->GetSelectedStatement();
	}
}

void Delete::Execute() {
	ReadActionParameters();
	if (TargetConnector) {
		pManager->SetSelectedConnector(nullptr);
		pManager->RemoveConnector(TargetConnector);
		delete TargetConnector;
	}
	if (TargetStatement) {
		pManager->SetSelectedStatement(nullptr);
		pManager->RemoveStatement(TargetStatement);
		if (TargetStatement->GetInlet().IsValid()) {
			Connector* conn;
			do{
				conn = pManager->GetConnector(TargetStatement->GetInlet());
				pManager->RemoveConnector(conn);
				delete conn;
			} while (conn);
		}
		if (TargetStatement->GetOutlet().IsValid()) {
			Connector* conn;
			do {
				conn = pManager->GetConnector(TargetStatement->GetOutlet());
				pManager->RemoveConnector(conn);
				delete conn;
			} while (conn);
		}
		if (TargetStatement->GetFalseOutlet().IsValid()) {
			Connector* conn;
			do {
				conn = pManager->GetConnector(TargetStatement->GetFalseOutlet());
				pManager->RemoveConnector(conn);
				delete conn;
			} while (conn);
		}
		delete TargetStatement;
	}
}
