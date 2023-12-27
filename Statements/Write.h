#pragma once
#include "Statement.h"

class Write : public Statement {
	private:
		Connector* pOutConn;

		Point bottomLeft;
		Point bottomRight;
		Point topLeft;
		Point topRight;

	protected:
		virtual void UpdateStatementText() override;

	public:
		Write(Point Left, string text = "");
		virtual Point GetFalseOutlet() const override;
		virtual void Draw(Output* pOut) const override;
		bool ClickOnStatement(Point click) const override;
		virtual void Save(ofstream& OutFile) override;
};