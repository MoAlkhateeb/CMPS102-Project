#ifndef VALUE_ASSIGN_H
#define VALUE_ASSIGN_H

#include "Statement.h"

//Value Assignment statement class
//The value assignment statement assigns a value to a variable
class ValueAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	double RHS;	//Right Handside (Value)
	
	Connector* pOutConn;

	Point LeftCorner;

	virtual void UpdateStatementText() override;
	
public:
	ValueAssign(Point Lcorner, string LeftHS="", double RightHS=0);
	
	void setLHS(const string &L);
	void setRHS(double R);

	virtual void Draw(Output* pOut) const override;
	bool ClickOnStatement(Point click) const override;

	virtual Point GetFalseOutlet() const override;
	virtual void Save(ofstream& OutFile) override;
};

#endif