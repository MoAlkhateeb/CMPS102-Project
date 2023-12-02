#include "Output.h"



Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1200;
	UI.height = 620;
	UI.wx = 15;
	UI.wy = 15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
#include <iostream>
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	ClearToolBar();
	UI.AppMode = DESIGN;	//Design Mode
	
	//fill the tool bar 
		
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem

	string MenuItemImages[DSN_ITM_CNT];
	MenuItemImages[ITM_LOAD] = "images\\load.jpg";
	MenuItemImages[ITM_SAVE] = "images\\save.jpg";
	MenuItemImages[ITM_SELECT] = "images\\select.jpg";
	//MenuItemImages[ITM_EDIT] = "images\\edit.jpg";
	//MenuItemImages[ITM_COPY] = "images\\copy.jpg";
	//MenuItemImages[ITM_CUT] = "images\\cut.jpg";
	//MenuItemImages[ITM_PASTE] = "images\\paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\delete.jpg";
	MenuItemImages[ITM_START] = "images\\start.jpg";
	MenuItemImages[ITM_END] = "images\\end.jpg";
	MenuItemImages[ITM_READ] = "images\\read.jpg";
	MenuItemImages[ITM_WRITE] = "images\\write.jpg";
	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\assignValue.jpg";
	MenuItemImages[ITM_VAR_ASSIGN] = "images\\assignVariable.jpg";
	MenuItemImages[ITM_OPER_ASSIGN] = "images\\assignOperation.jpg";
	MenuItemImages[ITM_COND] = "images\\conditional.jpg";
	MenuItemImages[ITM_CONNECTOR] = "images\\connector.jpg";
	MenuItemImages[ITM_SIM_MODE] = "images\\simulationMode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < DSN_ITM_CNT; i++) {
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}


	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{	
	ClearToolBar();
	UI.AppMode = SIMULATION;	//Simulation Mode
	string MenuItemImages[SIM_ITM_CNT];
	MenuItemImages[ITM_VALIDATE] = "images\\validate.jpg";
	MenuItemImages[ITM_RUN] = "images\\runSimulation.jpg";
	MenuItemImages[ITM_DESIGN_MODE] = "images\\designMode.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < SIM_ITM_CNT; i++) {
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}


	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	int sWidth, sHeight;
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
	
	pWind->GetStringSize(sWidth, sHeight, Text);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width / 2 - sWidth / 2, Left.y + height / 2 - sHeight / 2, Text);
}

void Output::DrawStart(Point Left, int width, int height, bool Selected) {

	const string text = "start";
	int sWidth, sHeight;

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	pWind->GetStringSize(sWidth, sHeight, text);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 2 - sWidth / 2, Left.y + height / 2 - sHeight / 2, text);
}
void Output::DrawEnd(Point Left, int width, int height, bool Selected) {

	const string text = "end";
	int sWidth, sHeight;

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	pWind->GetStringSize(sWidth, sHeight, text);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 2 - sWidth / 2, Left.y + height / 2 - sHeight / 2, text);
}

void Output::DrawConditionalStat(Point Left, int width, int height, string Text, bool Selected) {

	int sWidth, sHeight;

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	
	const int vertices = 4;
	const int xValues[vertices] = { Left.x, Left.x + width / 2, Left.x + width, Left.x + width / 2 };
	const int yValues[vertices] = { Left.y, Left.y + height / 2, Left.y, Left.y - height / 2 };

	//Draw the statement block rectangle
	pWind->DrawPolygon(xValues, yValues, vertices);

	pWind->GetStringSize(sWidth, sHeight, Text);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 2 - sWidth/2, Left.y - sHeight / 2, Text);
}

void Output::DrawRead(Point Left, int width, int height, string text, bool Selected) {
	
	int sWidth, sHeight;
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	const int vertices = 4;
	const int xValues[vertices] = { Left.x, Left.x + width / 4, Left.x + width + width / 4, Left.x + width };
	const int yValues[vertices] = { Left.y, Left.y - height, Left.y - height, Left.y };

	//Draw the statement block rectangle
	pWind->DrawPolygon(xValues, yValues, vertices);

	pWind->GetStringSize(sWidth, sHeight, text);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y - height, "READ");
	pWind->DrawString(Left.x + width / 2 - sWidth / 2, Left.y - height / 2 + sHeight / 2, text);
}

void Output::DrawWrite(Point Left, int width, int height, string text, bool Selected) {

	int sWidth, sHeight;
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	const int vertices = 4;
	const int xValues[vertices] = { Left.x, Left.x + width / 4, Left.x + width + width / 4, Left.x + width };
	const int yValues[vertices] = { Left.y, Left.y - height, Left.y - height, Left.y };

	//Draw the statement block rectangle
	pWind->DrawPolygon(xValues, yValues, vertices);

	pWind->GetStringSize(sWidth, sHeight, text);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y - height, "WRITE");
	pWind->DrawString(Left.x + width / 2 - sWidth / 2, Left.y - height / 2 + sHeight / 2, text);
}

void Output::DrawConnector(Point start, Point end, bool Selected) {
	if (Selected)	//if connector is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	
	pWind->DrawLine(start.x, start.y, end.x, end.y);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
