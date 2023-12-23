
#include "SelectDeselect.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

using namespace std;


SelectDeselect::SelectDeselect(ApplicationManager* pAppManager) : Action(pAppManager) {
	TargetStatement = nullptr;
	TargetConnector = nullptr;
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
	ReadActionParameters();
	
	if (TargetStatement) {
		if (TargetStatement->IsSelected()) {
			TargetStatement->SetSelected(false);
			pManager->SetSelectedStatement(nullptr);
		}
		else {
			if (pManager->GetSelectedConnector()) {
				pManager->GetSelectedConnector()->SetSelected(false);
				pManager->SetSelectedConnector(nullptr);
			}
			if (pManager->GetSelectedStatement()) {
				pManager->GetSelectedStatement()->SetSelected(false);
			}
			TargetStatement->SetSelected(true);
			pManager->SetSelectedStatement(TargetStatement);
		}
	}

	if (TargetConnector) {
		if (TargetConnector->IsSelected()) {
			TargetConnector->SetSelected(false);
			pManager->SetSelectedConnector(nullptr);
		}
		else {
			if (pManager->GetSelectedConnector()) {
				pManager->GetSelectedConnector()->SetSelected(false);
			}
			if (pManager->GetSelectedStatement()) {
				pManager->GetSelectedStatement()->SetSelected(false);
				pManager->SetSelectedStatement(nullptr);
			}
			TargetConnector->SetSelected(true);
			pManager->SetSelectedConnector(TargetConnector);
		}
	}
}