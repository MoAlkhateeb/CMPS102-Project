#pragma once
#include "Statement.h"

class Start : public Statement {

private:
	Point LeftCorner;	//left corner of the statement block.
	Connector* pOutConn;

protected:
	virtual void UpdateStatementText() override;

public: 
	Start(Point Left);
	virtual void Draw(Output* pOut) const override;
	bool ClickOnStatement(Point click) const override;

	virtual Point GetInlet() const override;
	virtual Point GetFalseOutlet() const override;
	virtual void Save(ofstream& OutFile) override;
};