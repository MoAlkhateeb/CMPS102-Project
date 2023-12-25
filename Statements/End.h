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

	virtual Point GetInlet() const;
	virtual Point GetOutlet() const;
	virtual Point GetFalseOutlet() const;
	virtual void Save(ofstream& OutFile) override;
};