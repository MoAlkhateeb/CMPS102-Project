#include "Statement.h"

int Statement::CreatedStatements = 0;

Statement::Statement()	
{ 
	ID = CreatedStatements++;
	Text = "";
	Selected = false;		
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

int Statement::GetID() const {
	return ID;
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

STAT_TYPE Statement::getType() const {
	return Type;
}

string Statement::getText() const {
	return Text;
}