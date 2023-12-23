
#include "SelectDeselect.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

using namespace std;


SelectDeselect::SelectDeselect(ApplicationManager* pAppManager) : Action(pAppManager) {
	TargetStatement = nullptr;
	TargetConnector = nullptr;

	ReadActionParameters();
}


void SelectDeselect::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Select/Deselect: Click on a statement to select or deselect it.");
	pIn->GetPointClicked(Position);
	
	TargetStatement = pManager->GetStatement(Position);
	TargetConnector = pManager->GetConnector(Position);

	pOut->ClearStatusBar();
}

void SelectDeselect::Execute() {

	if (TargetStatement) {
		if (TargetStatement->IsSelected()) {
			TargetStatement->SetSelected(false);
		}
		else {
			TargetStatement->SetSelected(true);
		}
	}

	if (TargetConnector) {
		if (TargetConnector->IsSelected()) {
			TargetConnector->SetSelected(false);
		}
		else {
			TargetConnector->SetSelected(true);
		}
	}
}