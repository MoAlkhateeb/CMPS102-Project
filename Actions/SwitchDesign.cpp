#include "Action.h"

#include "../ApplicationManager.h"
#include "SwitchDesign.h"
#include "../GUI/Output.h"


SwitchDesign::SwitchDesign(ApplicationManager* pAppManager) : Action(pAppManager) {}

void SwitchDesign::ReadActionParameters() {}

void SwitchDesign::Execute() {
	Output* pOut = pManager->GetOutput();

	pOut->ClearToolBar();
	pOut->CreateDesignToolBar();
}
