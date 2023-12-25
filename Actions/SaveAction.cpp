#include"../Actions/SaveAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <iostream>
#include <fstream>

SaveAction::SaveAction(ApplicationManager* pAppManager):Action(pAppManager){}

void SaveAction::Execute() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Enter the filename to save: ");
	string filename = pIn->GetString(pOut) + ".txt"; // Assuming a text file format
	
	ofstream outFile;
	outFile.open(filename);

	if (outFile.is_open()) {
		pManager->SaveAll(filename);
		outFile.close();
		pOut->PrintMessage("Flowchart saved successfully to " + filename);
	}
	else {
		pOut->PrintMessage("Error: Could not open file " + filename);
	}
}