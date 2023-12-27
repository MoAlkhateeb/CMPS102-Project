#include"../Actions/SaveAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <iostream>

SaveAction::SaveAction(ApplicationManager* pAppManager):Action(pAppManager){}


void SaveAction::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Enter the filename to save: ");
	filename = pIn->GetString(pOut);
	int length = filename.length();

	string suffix = filename.substr(length - 4, length - 1);
	cout << suffix << endl;
	for (int i = 0; i < suffix.length(); i++) {
		suffix[i] = tolower(suffix[i]);
	}

	if (suffix != ".txt") {
		filename += ".txt";
	}
}

void SaveAction::Execute() {
	ReadActionParameters();
	pManager->SaveAll(filename);
}