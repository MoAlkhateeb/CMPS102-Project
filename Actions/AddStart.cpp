#include "AddStart.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Start.h"

AddStart::AddStart(ApplicationManager* pAppManager) : Action(pAppManager) {}

//Read Assignemt statements position
void AddStart::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Start Statement: Click to add the statement");
	pIn->GetPointClicked(Position);

	pOut->ClearStatusBar();
}

//Create and add an assignemnt statement to the list of statements
void AddStart::Execute() {
	ReadActionParameters();

	Start* pStart = new Start(Position);
	pManager->AddStatement(pStart); 
}