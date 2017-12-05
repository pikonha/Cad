#pragma once
#ifndef INCLUDED_MAINCMDBEZIER_H
#define INCLUDED_MAINCMDBEZIER_H
#include "MainCmd.h"

class Bezier;

class MainCmdBezier : public MainCmd
{
private:
	Bezier* bezier;
public:
	MainCmdBezier(Data* d, MainView* s, Form f) : MainCmd(d, s, f) {}
	~MainCmdBezier() {}
	
	void execute();

	void setP1(Point p);
	void setP2(Point p);
	void setP3(Point p);

	Item* getItem() { return bezier; }

	void draw();

};

#endif