#pragma once

#include "Statement.h"

class VariableAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS;	//Right Handside of the assignment (name of a variable)

	Connector* pOutConn;

	Point Inlet;
	Point Outlet;

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText() override;

public:
	VariableAssign(Point Lcorner, string LeftHS = "", string RightHS = "");

	void setLHS(const string& leftVar);
	void setRHS(const string& rightvar);

	virtual void Draw(Output* pOut) const;

	bool ClickOnStatement(Point click) const override;
};