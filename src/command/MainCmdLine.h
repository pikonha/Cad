#pragma once
#ifndef INCLUDED_MAINCMDLINE_H
#define INCLUDED_MAINCMDLINE_H
#include "MainCmd.h"
#include "Line.h"
#include "LineModel.h"

class MainCmdLine :	public MainCmd
{
private:
	Line* line;
public:
	MainCmdLine(MainScreen* view, Form f) : MainCmd(view, f) {}
	~MainCmdLine() {}

	void execute(Data& d, MainScreen& s);
	
	void setP1(Point p);
	void setP2(Point p);

	Item* getItem() { return line; }

	QGraphicsItem* getModel();
};

#endif