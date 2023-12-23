#pragma once
#include "Statement.h"

class Write : public Statement {
	private:
		Connector* pOutConn;

		Point Inlet;
		Point Outlet;

		Point LeftCorner;

	protected:
		virtual void UpdateStatementText() override;

	public:
		Write(Point Left, string text = "");
		virtual void Draw(Output* pOut) const override;
		bool ClickOnStatement(Point click) const override;
};