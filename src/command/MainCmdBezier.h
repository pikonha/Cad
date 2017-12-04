#pragma once
#ifndef INCLUDED_MAINCMDBEZIER_H
#define INCLUDED_MAINCMDBEZIER_H
#include "MainCmd.h"

class Bezier;

class MainCmdBezier : public MainCmd
{
private:
	Bezier* bezier;

	bool drawingBezier;
public:
	MainCmdBezier(Data* d, MainScreen* s) : MainCmd(d, s) { drawingBezier = false; }
	~MainCmdBezier() {}
	
	void execute();

	void setP1(Point p);
	void setP2(Point p);
	void setP3(Point p);

	void draw();

	void moveMouse();
	void pressMouse();
	void releaseMouse();
};

#endif