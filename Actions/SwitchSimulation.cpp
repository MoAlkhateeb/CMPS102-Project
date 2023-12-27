#include "Action.h"

#include "../ApplicationManager.h"
#include "SwitchSimulation.h"
#include "../GUI/Output.h"


SwitchSimulation::SwitchSimulation(ApplicationManager* pAppManager) : Action(pAppManager) {}

void SwitchSimulation::ReadActionParameters() {}

void SwitchSimulation::Execute() {
	Output* pOut = pManager->GetOutput();

	pOut->ClearToolBar();
	pOut->CreateSimulationToolBar();
}
