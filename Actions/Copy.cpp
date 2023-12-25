#include "Copy.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"


Copy::Copy(ApplicationManager* pAppManager) :Action(pAppManager) {
	TargetStatment = nullptr;
}

void Copy::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	TargetStatment = pManager->GetSelectedStatement();

	if (TargetStatment) {
		pOut->PrintMessage("Statement copied to clipboard.");
	}
	else {
		pOut->PrintMessage("No Statement selected.");
	}

}

void Copy::Execute() {
	ReadActionParameters();
	if (TargetStatment) {
		pManager->SetClipboard(TargetStatment);
	}
}
