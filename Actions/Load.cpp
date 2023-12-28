#include "Load.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <iostream>
#include <fstream>

LoadAction::LoadAction(ApplicationManager* pAppManager) :Action(pAppManager) {}

void LoadAction::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Enter the filename to load: ");
	filename = pIn->GetString(pOut);
	int length = filename.length();

	string suffix = filename.substr(length - 4, length - 1);
	for (int i = 0; i < suffix.length(); i++) {
		suffix[i] = tolower(suffix[i]);
	}
	if (suffix != ".txt") {
		filename += ".txt";
	}
}

void LoadAction::Execute() {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();

	ifstream inFile(filename);

	if (inFile.is_open()) {
		pManager->LoadAll(inFile);
		pOut->PrintMessage("Flowchart loaded successfully from: " + filename);
	}
	else {
		pOut->PrintMessage("Could not Open file: " + filename);
	}
}