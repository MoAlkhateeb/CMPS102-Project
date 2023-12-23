#include "AddWrite.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddWrite::AddWrite(ApplicationManager* pAppManager) : Action(pAppManager){

}

void AddWrite::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Write Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter text for write statement: ");
	
	Text = pIn->GetString(pOut);

	pOut->ClearStatusBar();
}

void AddWrite::Execute() {
	ReadActionParameters();

	Write* pWrite = new Write(Position, Text);
	pManager->AddStatement(pWrite);
}
