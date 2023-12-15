#ifndef OUPTUT_H
#define OUPTUT_H

#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();	

	window* CreateWind(int, int, int , int);
	Input* CreateInput(); //Creates a pointer to the Input object	

	void CreateStatusBar(); //Creates status bar

	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar(); //Tool bar of the simulation mode

	void ClearStatusBar();	//Clears the status bar
	void ClearDrawArea();	//Clears the drawing area
	void ClearOutputBar(); //Clears the Output bar

	void ClearToolBar();
	
	void PrintMessage(string msg);	//Prints a message on Status bar
	void DrawString(const int, const int, const string);  //Writes a string in the specified location

	// -- Statements Drawing Functions
	void DrawStart(Point Ledt, int width, int height, bool Selected = false);
	void DrawEnd(Point Left, int width, int height, bool Selected = false);
	void DrawAssign(Point Left, int width, int height, string Text, bool Selected = false);
	void DrawConditionalStat(Point Left, int width, int height, string Text, bool Selected = false);
	void DrawRead(Point Left, int width, int height, string text, bool Selected = false);
	void DrawWrite(Point Left, int width, int height, string text, bool Selected = false);
	void DrawConnector(Point start, Point end, bool Selected = false);

	// draws an arow head in different orientations
	void DrawArrowHead(Point end, ArrowDirection direction, bool Selected = false);
	~Output();
};

#endif