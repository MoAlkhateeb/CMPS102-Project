#include "Run.h"
#include "..\ApplicationManager.h"

Run::Run(ApplicationManager* pAppManager) : Action(pAppManager) {
	valid = false;
}


void Run::ReadActionParameters() {	
	Output* pOut = pManager->GetOutput();
	valid = pManager->ValidateAll();
}

void Run::Execute() {
	ReadActionParameters();
	if (valid)
		pManager->ExecuteFlowchart();
}
