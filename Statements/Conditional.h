#pragma once

#include "Statement.h"


class Conditional : public Statement
{
private:
	string LHS;
	string OP;
	string RHS;

	Connector* pOutConn;
	
	Point Inlet;
	Point Outlet;

	Point LeftCorner;

	virtual void UpdateStatementText() override;

public:
	Conditional(Point Lcorner, string LeftHS = "", string Operator = "", string RightHS = "");

	void setLHS(const string& L);
	void setOperator(const string& O);
	void setRHS(const string& R);

	virtual void Draw(Output* pOut) const override;
	bool ClickOnStatement(Point click) const override;
};
