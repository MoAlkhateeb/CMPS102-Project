#pragma once

#include "Statement.h"

class Read : public Statement {

private:
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

	virtual Point GetFalseOutlet() const override;
	virtual void Save(ofstream& OutFile) override;
	static Read* Load(ifstream& InFile);
};