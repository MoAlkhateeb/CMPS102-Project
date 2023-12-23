#pragma once
#include "Statement.h"

class Start : public Statement {

private:
	Point Outlet;
	Point LeftCorner;	//left corenr of the statement block.
	Connector* pOutConn;

protected:
	virtual void UpdateStatementText() override;

public: 
	Start(Point Left);
	virtual void Draw(Output* pOut) const override;
	bool ClickOnStatement(Point click) const override;
};