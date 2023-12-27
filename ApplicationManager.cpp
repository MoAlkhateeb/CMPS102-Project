#include "ApplicationManager.h"
#include "Actions\AddConn.h"
#include "Actions\AddValueAssign.h"
#include "Actions\AddConditional.h"
#include "Actions\AddVariableAssign.h"
#include "Actions\AddOperatorAssign.h"
#include "Actions\SelectDeselect.h"
#include "Actions\AddStart.h"
#include "Actions\AddEnd.h"
#include "Actions\AddWrite.h"
#include "Actions\AddRead.h"
#include "Actions\Exit.h"
#include "Actions\Delete.h"
#include "Actions\SaveAction.h"
#include "Actions\SwitchSimulation.h"
#include "Actions\SwitchDesign.h"
#include "Actions\Validate.h"
#include "Actions\Run.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Statements\ValueAssign.h"
#include "Statements\VariableAssign.h"
#include "Statements\OperatorAssign.h"
#include "Statements\Read.h"
#include "Statements\Write.h"
#include "Statements\End.h"
#include "Statements\Start.h"
#include "Statements\Conditional.h"
#include <set>
#include <unordered_map>
#include <sstream>

using namespace std;

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedConn = NULL;
	pSelectedStat = NULL;	//no Statement is selected yet
	pClipboard = NULL;
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to ActionType, create the corresponding action object
	switch (ActType)
	{
		case ADD_VALUE_ASSIGN:
			pAct = new AddValueAssign(this);
			break;

		case ADD_CONDITION:
			pAct = new AddConditional(this);
			break;

		case ADD_VAR_ASSIGN:
			pAct = new AddVariableAssign(this);
			break;

		case ADD_OPER_ASSIGN:
			pAct = new AddOperatorAssign(this);
			break;

		case ADD_START:
			pAct = new AddStart(this);
			break;

		case ADD_END:
			pAct = new AddEnd(this);
			break;

		case ADD_READ:
			pAct = new AddRead(this);
			break;

		case ADD_WRITE:
			pAct = new AddWrite(this);
			break;

		case SELECT:
			pAct = new SelectDeselect(this);
			break;

		case ADD_CONNECTOR:
			pAct = new AddConn(this);
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case DEL:
			pAct = new Delete(this);
			break;

		case SWITCH_SIM_MODE:
			pAct = new SwitchSimulation(this);
			break;

		case SWITCH_DSN_MODE:
			pAct = new SwitchDesign(this);
			break;

		case VALIDATE_FLOWCHART:
			pAct = new Validate(this);
			break;

		case RUN_SIM:
			pAct = new Run(this);
			break;

		case EXIT:
			pAct = new Exit(this);
			break;
		
		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	
}

////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL


	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities
	

	for (int i = 0; i < StatCount; i++) {
		if (StatList[i]->ClickOnStatement(P)) {
			return StatList[i];
		}
	}
	return nullptr;
}

Statement* ApplicationManager::GetStatement(int ID) const {
	for (int i = 0; i < StatCount; i++) {
		if (StatList[i]->GetID() == ID) {
			return StatList[i];
		}
	}
	return nullptr;
}

void ApplicationManager::AddConnector(Connector* pConn) {
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;

}

Connector* ApplicationManager::GetConnector(Point P) const {
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i]->ClickOnConnector(P)) {
			return ConnList[i];
		}
	}
	return nullptr;
}

int ApplicationManager::GetConnectorCount(Point P) const {
	int count = 0;
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i]->ClickOnConnector(P)) {
			count++;
		}
	}
	return count;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}


Connector* ApplicationManager::GetSelectedConnector() const
{
	return pSelectedConn;
}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedConnector(Connector* pConn)
{
	pSelectedConn = pConn;
}

////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement *ApplicationManager::GetClipboard() const
{	return pClipboard;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement *pStat)
{	pClipboard = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::RemoveStatement(Statement* pStat) {
	for (int i = 0; i < StatCount; i++) {
		if (StatList[i] == pStat) {
			StatList[i] = nullptr;
			StatList[i] = StatList[StatCount - 1];
			StatCount--;
		}
	}
}
void ApplicationManager::RemoveConnector(Connector* pConn) {
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] == pConn) {
			ConnList[i] = nullptr;
			ConnList[i] = ConnList[ConnCount - 1];
			ConnCount--;
		}
	}
}


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<ConnCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}
//==================================================================================//
//							SaveAll Functions							//
//==================================================================================//

void ApplicationManager::SaveAll(const string& filename) const{
	ofstream outFile(filename);

	if (!outFile.is_open()) {
		pOut->PrintMessage("Error: Could not open file " + filename);
		return;
	}

	 //Save Statements 
	outFile << StatCount << endl;
	for (int i = 0; i < StatCount; i++) {
		StatList[i]->Save(outFile);
	}
	//Save Connectors 
	outFile << ConnCount << endl;
	for (int i = 0; i < ConnCount; i++) {
		ConnList[i]->Save(outFile);
	}
	outFile.close();

}


bool ApplicationManager::ValidateAll() const {

	// Check number of end and start statements
	int countEnd = 0;
	int countStart = 0;

	Statement* start;
	Statement* end;

	for (int i = 0; i < StatCount; i++) {
		Statement* stat = StatList[i];
		if (stat->getType() == END) { 
			end = stat;
			countEnd++; 
		}
		else if (stat->getType() == START) {
			start = stat;
			countStart++;
		}

		// separating the logic for more meaningful error messages.
		if (countEnd > 1) {
			pOut->PrintMessage("Your flowchart must have exactly one end.");
			return false;
		}
		if (countStart > 1) {
			pOut->PrintMessage("Your flowchart must have exactly one start.");
		}
	}

	// descriptive error messages for missing start or end.
	if (countStart == 0) {
		pOut->PrintMessage("Your flowchart doesn't have a start.");
		return false;
	}
	if (countEnd == 0) {
		pOut->PrintMessage("Your flowchart doesn't have an end.");
		return false;
	}

	// check that chart has the correct num of connectors
	for (int i = 0; i < StatCount; i++) {
		Statement* stat = StatList[i];
		Point In = stat->GetInlet();
		Point Out = stat->GetOutlet();
		Point FOut = stat->GetFalseOutlet();

		// conditional
		if (stat->getType() == COND) {
			if (GetConnectorCount(Out) != 1 || GetConnectorCount(FOut) != 1 || GetConnectorCount(In) < 1) {
				pOut->PrintMessage("A Conditional doesn't have correct number of connectors.");
				return false;
			}
		}

		// end statement
		else if (stat->getType() == END) {
			if (GetConnectorCount(In) < 1) {
				pOut->PrintMessage("No connector going into end.");
				return false;
			}
		}
		
		// start 
		else if (stat->getType() == START) {
			if (GetConnectorCount(Out) != 1) {
				pOut->PrintMessage("No connector coming out of start");
				return false;
			}
		}
		// normal statement (but not start or end)
		else {
			if (GetConnectorCount(Out) != 1 || GetConnectorCount(In) < 1) {
				pOut->PrintMessage("The chart doesn't have the correct number of connectors");
				return false;
			}
		}
	}

	set<string> variables;

	// check variables are initialized before use
	Statement* current = GetConnector(start->GetOutlet())->getDstStat();

	// trivial flowchart
	if (current->getType() == END) return true;

	Statement* otherBranchStat = nullptr;
	while (true) {
		if (dynamic_cast<ValueAssign*>(current)) {
			ValueAssign* valAssign = dynamic_cast<ValueAssign*>(current);
			variables.insert(valAssign->getLHS());
		}
		else if (dynamic_cast<Conditional*>(current)) {
			Conditional* conditional = dynamic_cast<Conditional*>(current);
			string LHS = conditional->getLHS();
			string RHS = conditional->getRHS();

			if (ValueOrVariable(LHS) == VARIABLE_OP && !variables.count(LHS)) {
				pOut->PrintMessage("Left hand side variable in conditional used before initialization.");
				return false;
			}
			else if (ValueOrVariable(RHS) == VARIABLE_OP && !variables.count(RHS)) {
				pOut->PrintMessage("Right hand side variable in conditional used before initialization.");
				return false;
			}
		}
		else if (dynamic_cast<VariableAssign*>(current)) {
			VariableAssign* varAssign = dynamic_cast<VariableAssign*>(current);
			string LHS = varAssign->getLHS();
			string RHS = varAssign->getRHS();

			if (!variables.count(RHS)) {
				pOut->PrintMessage("Right hand side variable in variable assignment used before initialization.");
				return false;
			}
			variables.insert(LHS);
		}
		else if (dynamic_cast<OperatorAssign*>(current)) {
			OperatorAssign* opAssign = dynamic_cast<OperatorAssign*>(current);
			string LHS = opAssign->getLHS();
			string RHS1 = opAssign->getRHS1();
			string RHS2 = opAssign->getRHS2();

			if (ValueOrVariable(RHS1) == VARIABLE_OP && !variables.count(RHS1)) {
				pOut->PrintMessage("First Right hand side variable in Operator Assign used before initialization.");
				return false;
			}
			else if (ValueOrVariable(RHS2) == VARIABLE_OP && !variables.count(RHS2)) {
				pOut->PrintMessage("Second Right hand side variable in Operator Assign used before initialization.");
				return false;
			}
			variables.insert(LHS);
		}
		else if (current->getType() == READ) {
			variables.insert(current->getText());
		}
		else if (current->getType() == WRITE) {
			if (!variables.count(current->getText())) {
				pOut->PrintMessage("Variable used before initialization in write.");
				return false;
			}
		}
		if (current->getType() == COND) {
			otherBranchStat = GetConnector(current->GetFalseOutlet())->getDstStat();
		}
		current = GetConnector(current->GetOutlet())->getDstStat();
		if (current->getType() == END) {
			if (otherBranchStat) {
				current = otherBranchStat;
				otherBranchStat = nullptr;
			} 
			else {
				return true;
			}
		}
	}

	return true;
}
 
void ApplicationManager::ExecuteFlowchart() {
	unordered_map<string, double> variables;
	
	// get start and end
	Statement* start = nullptr;
	Statement* end = nullptr;

	for (int i = 0; i < StatCount; i++) {
		if (StatList[i]->getType() == START) {
			start = StatList[i];
		}
		else if (StatList[i]->getType() == END) {
			end = StatList[i];
		}
		else if (start && end) {
			break;
		}
	}

	// traverse and execute
	Statement* current = GetConnector(start->GetOutlet())->getDstStat();

	// trivial flowchart
	if (current->getType() == END) return;

	bool TrueOutlet = false;
	while (true) {
		if (dynamic_cast<ValueAssign*>(current)) {
			ValueAssign* valAssign = dynamic_cast<ValueAssign*>(current);
			variables[valAssign->getLHS()] = valAssign->getRHS();
		}
		else if (dynamic_cast<Conditional*>(current)) {
			Conditional* conditional = dynamic_cast<Conditional*>(current);
			string LHS = conditional->getLHS();
			string RHS = conditional->getRHS();
			string OP = conditional->getOperator();

			double val1, val2;

			if (ValueOrVariable(LHS) == VARIABLE_OP) val1 = variables[LHS];
			else val1 = stod(LHS);

			if (ValueOrVariable(RHS) == VARIABLE_OP) val2 = variables[RHS];
			else val2 = stod(RHS);

			if (OP == "==") TrueOutlet = val1 == val2;
			else if (OP == ">") TrueOutlet = val1 > val2;
			else if (OP == "<") TrueOutlet = val1 < val2;
			else if (OP == ">=") TrueOutlet = val1 >= val2;
			else if (OP == "<=") TrueOutlet = val1 <= val2;
		}

		else if (dynamic_cast<VariableAssign*>(current)) {
			VariableAssign* varAssign = dynamic_cast<VariableAssign*>(current);
			string LHS = varAssign->getLHS();
			string RHS = varAssign->getRHS();
			variables[LHS] = variables[RHS];
		}

		else if (dynamic_cast<OperatorAssign*>(current)) {
			OperatorAssign* opAssign = dynamic_cast<OperatorAssign*>(current);
			string LHS = opAssign->getLHS();
			string RHS1 = opAssign->getRHS1();
			string RHS2 = opAssign->getRHS2();
			string OP = opAssign->getOP();

			double val1, val2;
			if (ValueOrVariable(RHS1) == VARIABLE_OP) val1 = variables[RHS1];
			else val1 = stod(RHS1);

			if (ValueOrVariable(RHS2) == VARIABLE_OP) val2 = variables[RHS2];
			else val2 = stod(RHS2);

			switch (OP[0]) {
			case '+':
				variables[LHS] = val1 + val2;
				break;
			case '-':
				variables[LHS] = val1 - val2;
				break;
			case '*':
				variables[LHS] = val1 * val2;
				break;
			case '/':
				variables[LHS] = val1 / val2;
				break;
			}
		}

		else if (current->getType() == READ) {
			variables[current->getText()] = pIn->GetValue(pOut);
		}

		else if (current->getType() == WRITE) {
			pOut->PrintMessage(std::to_string(variables[current->getText()]));
		}


		if (current->getType() == COND) {
			if (TrueOutlet)
				current = GetConnector(current->GetOutlet())->getDstStat();
			else 
				current = GetConnector(current->GetFalseOutlet())->getDstStat();

			TrueOutlet = false;
		}
		else {
			current = GetConnector(current->GetOutlet())->getDstStat();
		}

		if (current->getType() == END) {
			return;
		}
	}
}