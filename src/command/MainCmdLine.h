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
	MainCmdLine(Data* d, MainScreen* s) : MainCmd(d, s) {}
	~MainCmdLine() {}

	void execute();
	
	void setP1(Point p);
	void setP2(Point p);

	void draw();

	void moveMouse();
	void pressMouse();
	void releaseMouse();
};

#endif