#include "AddEnd.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\End.h"

AddEnd::AddEnd(ApplicationManager* pAppManager) : Action(pAppManager) {}

//Read Assignemt statements position
void AddEnd::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("End Statement: Click to add the statement");
	pIn->GetPointClicked(Position);

	pOut->ClearStatusBar();
}

//Create and add an assignemnt statement to the list of statements
void AddEnd::Execute() {
	ReadActionParameters();

	End* pEnd = new End(Position);
	pManager->AddStatement(pEnd);
}