#include "AddRead.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddRead::AddRead(ApplicationManager* pAppManager) : Action(pAppManager) {

}

void AddRead::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Write Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	Text = pIn->GetVariable(pOut);

	pOut->ClearStatusBar();
}

void AddRead::Execute() {
	ReadActionParameters();

	Read* pRead = new Read(Position, Text);
	pManager->AddStatement(pRead);
}
