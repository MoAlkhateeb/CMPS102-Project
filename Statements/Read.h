#pragma once

#include "Statement.h"

class Read : public Statement {

private:
	Connector* pOutConn;

	Point Inlet;
	Point Outlet;

	Point bottomLeft;
	Point bottomRight;
	Point topLeft;
	Point topRight;

protected:
	virtual void UpdateStatementText() override;

public: 
	Read(Point Left, string text = "");
	virtual void Draw(Output* pOut) const override;
	bool ClickOnStatement(Point click) const override;

	virtual Point GetInlet() const;
	virtual Point GetOutlet() const;
	virtual Point GetFalseOutlet() const;
	virtual void Save(ofstream& OutFile) override;
};