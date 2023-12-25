#pragma once
#include "Statement.h"

class Start : public Statement {

private:
	Point Outlet;
	Point LeftCorner;	//left corner of the statement block.
	Connector* pOutConn;

protected:
	virtual void UpdateStatementText() override;

public: 
	Start(Point Left);
	virtual void Draw(Output* pOut) const override;
	bool ClickOnStatement(Point click) const override;

	virtual Point GetInlet() const;
	virtual Point GetOutlet() const;
	virtual Point GetFalseOutlet() const;
	virtual void Save(ofstream& OutFile) override;
};