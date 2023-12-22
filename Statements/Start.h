#pragma once

#include "Statements/Statement.h"

class Start : public Statement {

protected:
	virtual void UpdateStatementText() override;

public:
	Start();
	virtual void Draw(Output* pOut) const override;

};

