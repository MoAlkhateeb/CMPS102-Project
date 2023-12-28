#pragma once

#include "Statement.h"

class End : public Statement {
private:
	Point LeftCorner;	//left corner of the statement block.

protected:
	virtual void UpdateStatementText() override;

public:
	End(Point Left);
	virtual void Draw(Output* pOut) const override;
	bool ClickOnStatement(Point click) const override;

	virtual Point GetOutlet() const override;
	virtual Point GetFalseOutlet() const override;
	virtual void Save(ofstream& OutFile) override;
	static End* Load(ifstream& InFile);
};