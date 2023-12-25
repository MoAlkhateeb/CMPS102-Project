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