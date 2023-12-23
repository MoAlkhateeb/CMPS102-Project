#pragma once

#include "Statement.h"

class Read : public Statement {

private:
	Connector* pOutConn;

	Point Inlet;
	Point Outlet;

	Point LeftCorner; // bottom left

protected:
	virtual void UpdateStatementText() override;

public: 
	Read(Point Left, string text = "");
	virtual void Draw(Output* pOut) const override;
	bool ClickOnStatement(Point click) const override;
};