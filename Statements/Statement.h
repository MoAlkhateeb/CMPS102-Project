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

	Connector* OutConn;
	Connector* FalseOutConn;

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	


public:
	Statement();
	void SetSelected(bool s);
	bool IsSelected() const;
	STAT_TYPE getType() const;

	virtual int GetID() const;
	void SetID(int id);
	virtual void Draw(Output* pOut) const = 0 ;	//Draw the statement // Retaj

	virtual Point GetInlet() const;
	virtual Point GetOutlet() const;
	virtual Point GetFalseOutlet() const;

	virtual string getText() const;
	
	virtual Connector* GetOutConn() const;
	virtual Connector* GetFalseOutConn() const;
	virtual void setOutConn(Connector* Out);
	virtual void setFalseOutConn(Connector* FalseOut);

	virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file // Omar
	virtual bool ClickOnStatement(Point click) const = 0; // Retaj

};

#endif