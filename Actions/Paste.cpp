#include "Paste.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"


Paste::Paste(ApplicationManager* pAppManager) : Action(pAppManager) {
	TargetStatement = nullptr;

}

void Paste::ReadActionParameters(){
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	if (pManager->GetClipboard()) {
		TargetStatement = pManager->GetClipboard();
		pOut->PrintMessage("Click on new location to paste.");
		pIn->GetPointClicked(NewPosition);
	}
	else {
		pOut->PrintMessage("Clipboard is empty.");
	}
}
void Paste::Execute() {
	ReadActionParameters();
	if (!TargetStatement) return;
	

}