#ifndef STATEMENT_H
#define STATEMENT_H

#include "..\defs.h"
#include "..\Connector.h"
//class Output;
#include "..\GUI\Output.h"
#include <fstream>


enum STAT_TYPE {
	
	START,
	END,
	VAL_ASSIGN,
	VAR_ASSIGN,
	OP_ASSIGN,
	COND,
	READ,
	WRITE,
};

//Base class for all Statements
class Statement
{

protected:
	static int CreatedStatements;
	int ID;			//Each Statement has an ID --> must be unique
	string Text;	//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)
	bool Selected;	//true if the statement is selected on the folwchart

	STAT_TYPE Type;

	Point Inlet;
	Point Outlet;
	Point FalseOutlet;

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	


public:
	Statement();
	void SetSelected(bool s);
	bool IsSelected() const;
	STAT_TYPE getType() const;

	virtual int GetID() const;
	virtual void Draw(Output* pOut) const = 0 ;	//Draw the statement
	

	virtual Point GetInlet() const;
	virtual Point GetOutlet() const;
	virtual Point GetFalseOutlet() const;

	virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file

	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file

	//virtual void Edit() = 0;		//Edit the Statement parameter

	//virtual void Simulate();	//Execute the statement in the simulation mode

	//[BONUS] virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file


	virtual bool ClickOnStatement(Point click) const = 0;

};

#endif