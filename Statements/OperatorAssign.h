#pragma once

#include "Statement.h"


class OperatorAssign :public Statement {
private:
	string LHS; //Left Handside of the assignment (name of a variable)
	string RHS1; //Firts Right Handside Operand(variable name or constant)
	string RHS2; // Second Right Handside Operand(variable name or constant)

	string OP; // operator (+,-,*,/)

	Connector* pOutConn;

	Point Inlet; // A point where connections enter the statement
	Point Outlet; // A point where connections leaves the statement
	Point LeftCorner; // Left corner of the statment block

	virtual void UpdateStatementText() override;

public:
	OperatorAssign(Point Lcorner, const string& LeftHs = "", const string& RightHs1 = "", const string& RightHs2 = "", const string& OP = "");
	void setLHS(const string& L);
	void setRHS1(const string& RH1);
	void setRHS2(const string& RH2);
	void setOperator(const string& operation);

	virtual void Draw(Output* pOut) const override;

	bool ClickOnStatement(Point click) const override;

	virtual Point GetInlet() const;
	virtual Point GetOutlet() const;
	virtual Point GetFalseOutlet() const;
	void OperatorAssign::Save(ofstream& OutFile);
};