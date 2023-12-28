#include "Statement.h"

int Statement::CreatedStatements = 0;

Statement::Statement()	
{ 
	ID = CreatedStatements++;
	Text = "";
	Selected = false;
	OutConn = nullptr;
	FalseOutConn = nullptr;
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

int Statement::GetID() const {
	return ID;
}
void Statement::SetID(int id) {
	ID = id;
}
Point Statement::GetInlet() const {
	return Inlet;
}
Point Statement::GetOutlet() const {
	return Outlet;
}
Point Statement::GetFalseOutlet() const {
	return FalseOutlet;
}


Connector* Statement::GetOutConn() const {
	return OutConn;
}
Connector* Statement::GetFalseOutConn() const {
	return FalseOutConn;
}
void Statement::setOutConn(Connector* Out) {
	OutConn = Out;
}
void Statement::setFalseOutConn(Connector* FalseOut) {
	FalseOutConn = FalseOut;
}

STAT_TYPE Statement::getType() const {
	return Type;
}

string Statement::getText() const {
	return Text;
}