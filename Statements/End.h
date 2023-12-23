#pragma once

#include "Statement.h"

class End : public Statement {
private:
	Point Inlet;
	Point LeftCorner;	//left corenr of the statement block.
	Connector* pInConn;

protected:
	virtual void UpdateStatementText() override;

public:
	End(Point Left);
	virtual void Draw(Output* pOut) const override;
	bool ClickOnStatement(Point click) const override;
};