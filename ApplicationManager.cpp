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
#include "Actions\Copy.h"
#include "Actions\Delete.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
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

		case COPY:
			pAct = new Copy(this);
			break;

		case ADD_CONNECTOR:
			pAct = new AddConn(this);
			break;

		case DEL:
			pAct = new Delete(this);
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
		pOut->PrintMessage("Error: could not open file " + filename);
		return;
	}
	 //Save Statements 
	outFile << StatCount << endl;
	for (auto& stmt : StatList) {
		stmt->Save(outFile);
	}
	//Save Connectors 
	outFile << ConnCount << endl;
	for (auto& conn : ConnList) {
		conn->Save(outFile);
	}
	outFile.close();

}