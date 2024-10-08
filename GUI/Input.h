#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h"
#include "..\HelperFn.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;   //Class forward declaration
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window

public:
	
	//Consturctor
	Input(window* pW);
	
	//Gets coordinate where user clicks
	void GetPointClicked(Point &P) const;
	
	// Reads a double value from the user 
	double GetValue(Output* pO) const;

	//Returns a string entered by the user
	string GetString(Output* pO) const ;

	// reads a �variable name� from the user (from the keyboard). 
	string GetVariable(Output* pO) const;

	// reads an arithmetic operator (+, -, * or /) from the user. 
	string GetArithOperator(Output* pO) const;

	// similar to the previous function but for comparison operators (==, !=, <, <=, > or >=).
	string GetCompOperator(Output* pO) const;

	//Reads the user click and maps it to an action
	ActionType GetUserAction() const;

	~Input();
};

#endif