#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\DEFS.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
	
	int width, height;	//Window width and height
	int wx, wy;			//Window starting coordinates

	int StatusBarHeight;	//Status Bar Width
	int ToolBarHeight;		//Tool Bar Width
	int MenuItemWidth;		//Menu Item Width
	int DrawingAreaWidth;   //Drawing Area Width
	
	color DrawColor;		//Drawing color
	color HighlightColor;		//Highlighting color
	color MsgColor;		//Messages color

	int ASSGN_WDTH;		//Assignment statement default width
	int ASSGN_HI;		//Assignment statement default height
	
	int CONDITION_WDTH; //Conditional statement default width
	int CONDITION_HI; //Conditional statement default height

	int READ_WDTH; //Read statement default width
	int READ_HI;  //Read statement default height

	int WRITE_WDTH; //Write statement default width
	int WRITE_HI;  //Write statement default height

	int START_WDTH; //Start statement default width
	int START_HI;  //Start statement default height

	int END_WDTH; //End statement default width
	int END_HI;  //End statement default height

	int ArrowSideLength; // side length of the arrow
	double ArrowSpreadAngle; // angle between 2 side lengths of the arrow in degrees

}UI;	//create a single global object UI

enum ArrowDirection {
	LEFT,
	RIGHT, 
	UP,
	DOWN
};

struct Point	
{
	int x,y;
	Point(int a=0, int b=0)	//constructor
	{ x=a;	y=b;	}
};

#endif