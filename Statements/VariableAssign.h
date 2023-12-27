#pragma once

#include "Statement.h"

class VariableAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS;	//Right Handside of the assignment (name of a variable)

	Connector* pOutConn;

	Point LeftCorner;	//left corner of the statement block.

	virtual void UpdateStatementText() override;

public:
	VariableAssign(Point Lcorner, string LeftHS = "", string RightHS = "");

	void setLHS(const string& leftVar);
	void setRHS(const string& rightvar);
	string getLHS() const;
	string getRHS() const;

	virtual void Draw(Output* pOut) const;

	bool ClickOnStatement(Point click) const override;

	virtual Point GetFalseOutlet() const override;
	virtual void Save(ofstream& OutFile) override;
};