#ifndef STATEMENT_H
#define STATEMENT_H

#include "..\defs.h"
#include "..\Connector.h"
//class Output;
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all Statements
class Statement
{
protected:
	static int CreatedStatements;
	int ID;			//Each Statement has an ID --> must be unique
	string Text;	//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)
	bool Selected;	//true if the statement is selected on the folwchart


	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	


public:
	Statement();
	void SetSelected(bool s);
	bool IsSelected() const;
	
	virtual int GetID() const;
	virtual void Draw(Output* pOut) const = 0 ;	//Draw the statement
	

	virtual Point GetInlet() const = 0;
	virtual Point GetOutlet() const = 0;
	virtual Point GetFalseOutlet() const = 0;

	virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file

	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file

	//virtual void Edit() = 0;		//Edit the Statement parameter

	//virtual void Simulate();	//Execute the statement in the simulation mode

	//[BONUS] virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file


	virtual bool ClickOnStatement(Point click) const = 0;

};

#endif