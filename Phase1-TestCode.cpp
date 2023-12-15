
#include "HelperFn.h"
#include "GUI\Input.h"
#include "GUI\Output.h"


//This is a test code to test the Input and Output classes
int main()
{

	Point P;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 0:	Testing the helper functions
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST0: Testing the helper functions");
	pIn->GetPointClicked(P);	//Wait for any click

	string text;

	// testing IsValue and printing corresponding message
	pOut->PrintMessage("Testing IsValue... Enter text");
	text = pIn->GetString(pOut);
	if (IsValue(text))
		pOut->PrintMessage("Text is a Value.");
	else
		pOut->PrintMessage("Text is not a Value.");

	pIn->GetPointClicked(P);	//Wait for any click

	// testing IsVariable and printing corresponding message
	pOut->PrintMessage("Testing IsVariable... Enter text");
	text = pIn->GetString(pOut);
	if (IsVariable(text))
		pOut->PrintMessage("Text is a Variable.");
	else
		pOut->PrintMessage("Text is not a Variable.");

	pIn->GetPointClicked(P);	//Wait for any click

	// testing IsArithOperator and printing corresponding message
	pOut->PrintMessage("Testing IsArithOperator... Enter text");
	text = pIn->GetString(pOut);
	if (IsArithOperator(text))
		pOut->PrintMessage("Text is an arithmetic operator.");
	else
		pOut->PrintMessage("Text is not an arithmetic operator.");

	pIn->GetPointClicked(P);	//Wait for any click

	// testing IsCompOperator and printing corresponding message
	pOut->PrintMessage("Testing IsCompOperator... Enter text");
	text = pIn->GetString(pOut);
	if (IsCompOperator(text))
		pOut->PrintMessage("Text is a comparision operator.");
	else
		pOut->PrintMessage("Text is not a comparision operator.");

	pIn->GetPointClicked(P);	//Wait for any click

	// testing ValueOrVariable and printing corresponding message
	pOut->PrintMessage("Testing ValueOrVariable... Enter text");
	text = pIn->GetString(pOut);
	switch (ValueOrVariable(text)) {
		case VALUE_OP:
			pOut->PrintMessage("Text is a Value.");
			break;

		case VARIABLE_OP:
			pOut->PrintMessage("Text is a Variable.");
			break;
		case INVALID_OP:
			pOut->PrintMessage("Text is neither a variable nor a value.");
	}


	//Starting the input and output classes test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(P);	//Wait for any click
	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area, the output bar and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Statements with all possible states:
	//			Normal, highlighted, empty, filled with code
	//			Also drawing connectors
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any statement in any status, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click

	/// 2.1- Assignment statement test
	//Drawing assignment statements in all posible states
	
	pOut->PrintMessage("Drawing Simple Assignment statements in ALL STATES, Click to continue");
	
	//Drawing (normal) (empty) assignment statement --> STATE 1
	P.x = 100;	P.y = 100;
	pOut->DrawAssign(P,UI.ASSGN_WDTH, UI.ASSGN_HI, " = ");

	//Drawing (highlighted) (empty) assignment statement --> STATE 2
	P.x = 300;	P.y = 100;
	pOut->DrawAssign(P,UI.ASSGN_WDTH, UI.ASSGN_HI, " = ", true);

	//Drawing a resized empty assignment statement
	P.x = 100;	P.y = 200;
	pOut->DrawAssign(P,80, UI.ASSGN_HI, " = ");

	//Drawing edited (normal) (non-empty) assignment statement --> STATE 3
	P.x = 100;	P.y = 300;
	pOut->DrawAssign(P,UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000");

	//Drawing (highlighted) (non-empty) assignment statement --> STATE 4
	P.x = 300;	P.y = 300;
	pOut->DrawAssign(P,UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000", true);

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///2.2- Variable assignment & single operator assignment
	pOut->PrintMessage("Drawing other Assignment statements in ALL STATES, Click to continue");

	//Drawing edited (normal) (non-empty) assignment statement
	P.x = 300;	P.y = 100;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = X");

	//Drawing (highlighted) (non-empty) assignment statement
	P.x = 100;	P.y = 100;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = X", true);

	//Drawing edited (normal) (non-empty) assignment statement
	P.x = 300;	P.y = 300;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = A + 10");

	//Drawing (highlighted) (non-empty) assignment statement
	P.x = 100;	P.y = 300;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3 * 5", true);

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.3- Conditional statement test
	//Drawing Conditional statements in all posible states
	pOut->PrintMessage("Drawing Conditional Statement in ALL STATES, Click to continue");

	//Drawing edited (normal) (non-empty) coditional statement
	P.x = 100;	P.y = 100;
	pOut->DrawConditionalStat(P, UI.CONDITION_WDTH, UI.CONDITION_HI, "X > 100");

	//Drawing (highlighted) (non-empty) conditional statement
	P.x = 300;	P.y = 100;
	pOut->DrawConditionalStat(P, UI.CONDITION_WDTH, UI.CONDITION_HI, "Y == 2", true);

	P.x = 100;	P.y = 300;
	pOut->DrawConditionalStat(P, UI.CONDITION_WDTH, UI.CONDITION_HI, " >= ");

	//Drawing (highlighted) (non-empty) conditional statement
	P.x = 300;	P.y = 300;
	pOut->DrawConditionalStat(P, UI.CONDITION_WDTH, UI.CONDITION_HI, " == ", true);

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.6- Start & End statements test
	//Drawing Start & End statements in all posible states
	pOut->PrintMessage("Drawing Start & End Statements in ALL STATES, Click to continue");

	//Drawing edited (normal) end statement
	P.x = 100;	P.y = 100;
	pOut->DrawEnd(P, UI.END_WDTH, UI.END_HI);

	//Drawing (highlighted) end statement
	P.x = 100;	P.y = 300;
	pOut->DrawEnd(P, UI.END_WDTH, UI.END_HI, true);

	//Drawing (highlighted) start statement
	P.x = 300;	P.y = 100;
	pOut->DrawStart(P, UI.END_WDTH, UI.END_HI);

	//Drawing (highlighted) start statement
	P.x = 300;	P.y = 300;
	pOut->DrawStart(P, UI.END_WDTH, UI.END_HI, true);

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Read statement test
	//Drawing Read statements in all posible states
	pOut->PrintMessage("Drawing Read Statement in ALL STATES, Click to continue");

	P.x = 100;	P.y = 150;
	pOut->DrawRead(P, UI.READ_WDTH, UI.READ_HI, "X");

	P.x = 100;	P.y = 225;
	pOut->DrawRead(P, UI.READ_WDTH, UI.READ_HI, "Y", true);

	P.x = 100;	P.y = 400;
	pOut->DrawRead(P, UI.READ_WDTH, UI.READ_HI, "");

	P.x = 100;	P.y = 475;
	pOut->DrawRead(P, UI.READ_WDTH, UI.READ_HI, "", true);

	pIn->GetPointClicked(P);

	/// 2.5- Write statement test
	//Drawing Write statements in all posible states
	pOut->PrintMessage("Drawing Write Statement in ALL STATES, Click to continue");

	P.x = 400;	P.y = 150;
	pOut->DrawWrite(P, UI.WRITE_WDTH, UI.WRITE_HI, "Hello, world");

	P.x = 400;	P.y = 225;
	pOut->DrawWrite(P, UI.WRITE_WDTH, UI.WRITE_HI, "Hello, world", true);

	P.x = 400;	P.y = 400;
	pOut->DrawWrite(P, UI.WRITE_WDTH, UI.WRITE_HI, "");

	P.x = 400;	P.y = 475;
	pOut->DrawWrite(P, UI.WRITE_WDTH, UI.WRITE_HI, "", true);

	// wait before proceeding to the next test
	pIn->GetPointClicked(P);
	pOut->ClearDrawArea();

	/// 2.7- Connector test
	//Drawing Connector in all posible states
	pOut->PrintMessage("Drawing Connector in Normal and Highlighted STATES, Click to continue");

	pIn->GetPointClicked(P); //Wait for any click
	pOut->ClearDrawArea();
	
	Point start, end;
	pOut->PrintMessage("Click the start point.");
	pIn->GetPointClicked(start);

	pOut->PrintMessage("Click the end point.");
	pIn->GetPointClicked(end);
	pOut->DrawConnector(start, end, false);

	pOut->PrintMessage("Click the start point.");
	pIn->GetPointClicked(start); //Wait for any click

	pOut->PrintMessage("Click the end point.");
	pIn->GetPointClicked(end);	//Wait for any click
	pOut->DrawConnector(start, end, true);

	// wait before proceeding to the next test
	pIn->GetPointClicked(P);
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// SUBTEST: Draw arrow heads
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("Testing the ability to add arrowheads in different orientations and highlights");
	pIn->GetPointClicked(P); // Wait for any click

	pOut->PrintMessage("Click anywhere to add an unhighlighted UP arrow");
	pIn->GetPointClicked(P); // Wait for any click
	pOut->DrawArrowHead(P, UP);

	pOut->PrintMessage("Click anywhere to add an unhighlighted DOWN arrow");
	pIn->GetPointClicked(P); // Wait for any click
	pOut->DrawArrowHead(P, DOWN);

	pOut->PrintMessage("Click anywhere to add an unhighlighted RIGHT arrow");
	pIn->GetPointClicked(P); // Wait for any click
	pOut->DrawArrowHead(P, RIGHT);

	pOut->PrintMessage("Click anywhere to add an unhighlighted LEFT arrow");
	pIn->GetPointClicked(P); // Wait for any click
	pOut->DrawArrowHead(P, LEFT);

	pOut->PrintMessage("Click anywhere to add an highlighted UP arrow");
	pIn->GetPointClicked(P); // Wait for any click
	pOut->DrawArrowHead(P, UP, true);

	pOut->PrintMessage("Click anywhere to add an highlighted DOWN arrow");
	pIn->GetPointClicked(P); // Wait for any click
	pOut->DrawArrowHead(P, DOWN, true);

	pOut->PrintMessage("Click anywhere to add an highlighted RIGHT arrow");
	pIn->GetPointClicked(P); // Wait for any click
	pOut->DrawArrowHead(P, RIGHT, true);

	pOut->PrintMessage("Click anywhere to add an highlighted  LEFT arrow");
	pIn->GetPointClicked(P); // Wait for any click
	pOut->DrawArrowHead(P, LEFT, true);

	// wait before proceeding to next test
	pIn->GetPointClicked(P);
	pOut->ClearDrawArea();

	/// 2.8- Draw String TEST
	pOut->PrintMessage("Doing the draw string test, click to continue");
	pIn->GetPointClicked(P);

	pOut->PrintMessage("Enter a string");
	text = pIn->GetString(pOut);

	//Drawing a String in a specific location
	pOut->DrawString(100, 200, text);

	pOut->PrintMessage("String Drawn. Click to continue");

	// wait before proceeding to next test
	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings and a value from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings, values, variables and operators");
	
	double value = pIn->GetValue(pOut);
	pOut->PrintMessage(std::to_string(value));

	pIn->GetPointClicked(P);	//Wait for any click

	string name = pIn->GetVariable(pOut);
	pOut->PrintMessage(name);

	pIn->GetPointClicked(P);	//Wait for any click

	string arithOp = pIn->GetArithOperator(pOut);
	pOut->PrintMessage(arithOp);

	pIn->GetPointClicked(P);	//Wait for any click

	string compOp = pIn->GetCompOperator(pOut);
	pOut->PrintMessage(compOp);

	// wait before proceeding to next test
	pIn->GetPointClicked(P);
	pOut->ClearDrawArea();


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	// getting user actions and printing action
	ActionType ActType;
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_START:
			pOut->PrintMessage("Action: ADD_START");
			break;
		case ADD_END:
			pOut->PrintMessage("Action: ADD_END");
			break;
		case ADD_VALUE_ASSIGN:
			pOut->PrintMessage("Action: ADD_VALUE_ASSIGN");
			break;
		case ADD_VAR_ASSIGN:
			pOut->PrintMessage("Action: ADD_VAR_ASSIGN");
			break;
		case ADD_OPER_ASSIGN:
			pOut->PrintMessage("Action: ADD_OPER_ASSIGN");
			break;
		case ADD_CONDITION:
			pOut->PrintMessage("Action: ADD_CONDITION");
			break;
		case ADD_READ:
			pOut->PrintMessage("Action: ADD_READ");
			break;
		case ADD_WRITE:
			pOut->PrintMessage("Action: ADD_WRITE");
			break;
		case ADD_CONNECTOR:
			pOut->PrintMessage("Action: ADD_CONNECTOR");
			break;
		case SELECT:
			pOut->PrintMessage("Action: SELECT");
			break;
		case EDIT_STAT:
			pOut->PrintMessage("Action: EDIT_STAT");
			break;
		case DEL:
			pOut->PrintMessage("Action: DEL");
			break;
		case COPY:
			pOut->PrintMessage("Action: COPY");
			break;
		case CUT:
			pOut->PrintMessage("Action: CUT");
			break;
		case PASTE:
			pOut->PrintMessage("Action: PASTE");
			break;
		case SAVE:
			pOut->PrintMessage("Action: SAVE");
			break;
		case LOAD:
			pOut->PrintMessage("Action: LOAD");
			break;
		case SWITCH_DSN_MODE:
			pOut->PrintMessage("Action: SWITCH_DSN_MODE");
			pOut->CreateDesignToolBar();
			break;
		case SWITCH_SIM_MODE:
			pOut->PrintMessage("Action: SWITCH_SIM_MODE");
			pOut->CreateSimulationToolBar();
			break;
		case VALIDATE_FLOWCHART:
			pOut->PrintMessage("Action: VALIDATE_FLOWCHART");
			break;
		case RUN_SIM:
			pOut->PrintMessage("Action: RUN_SIM");
			break;
		case DRAWING_AREA:
			pOut->PrintMessage("Action: DRAWING_AREA");
			break;
		case OUTPUT_AREA:
			pOut->PrintMessage("Action: OUTPUT_AREA");
			break;
		case DSN_TOOL:
			pOut->PrintMessage("Action: DSN_TOOL");
			break;
		case SIM_TOOL:
			pOut->PrintMessage("Action SIM_TOOL");
			break;
		case STATUS:
			pOut->PrintMessage("Action: STATUS");
			break;
		case EXIT:
			break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(P);

	// deletng dynamically allocated objects
	delete pIn;
	delete pOut;	
	return 0;
}


