#pragma once

#include "Validate.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

Validate::Validate(ApplicationManager* pAppManager) : Action(pAppManager) {}
void Validate::ReadActionParameters() {}

void Validate::Execute() {
	Output* pOut = pManager->GetOutput();
	if (pManager->ValidateAll()) {
		pOut->PrintMessage("Chart Validated Successfully!");
	}
}