#pragma once

#include "Action.h"
#include "..\Statements\Statement.h"

class AddConn : public Action
{
private:
	Statement* Src;
	Statement* Dst;
	Point Start;
	Point End;

public:
	AddConn(ApplicationManager* pAppManager);

	virtual void ReadActionParameters() override;
	virtual void Execute() override;

};