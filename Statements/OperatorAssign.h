#pragma once

#include "Statement.h"


class OperatorAssign :public Statement {
private:
	string LHS; //Left Handside of the assignment (name of a variable)
	string RHS1; //Firts Right Handside Operand(variable name or constant)
	string RHS2; // Second Right Handside Operand(variable name or constant)

	string OP; // operator (+,-,*,/)

	Point LeftCorner; // Left corner of the statment block

	virtual void UpdateStatementText() override;

public:
	OperatorAssign(Point Lcorner, const string& LeftHs = "", const string& RightHs1 = "", const string& RightHs2 = "", const string& OP = "");
	void setLHS(const string& L);
	void setRHS1(const string& RH1);
	void setRHS2(const string& RH2);
	void setOperator(const string& operation);

	string getLHS() const;
	string getRHS1() const;
	string getRHS2() const;
	string getOP() const;

	virtual void Draw(Output* pOut) const override;

	bool ClickOnStatement(Point click) const override;

	virtual Point GetFalseOutlet() const override;

	void Save(ofstream& OutFile);
	static OperatorAssign* Load(ifstream& InFile);
};