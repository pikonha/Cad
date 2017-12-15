#pragma once
#ifndef INCLUDED_MAINCMDBEZIER_H
#define INCLUDED_MAINCMDBEZIER_H
#include "MainCmd.h"
#include "Bezier.h"

class MainCmdBezier : public MainCmd
{
private:
	Bezier* bezier;
public:
	MainCmdBezier(MainScreen& view) : MainCmd(view) { form = BEZIER; }
	~MainCmdBezier() {}
	
	void execute(Data& d, MainScreen& s);

	void setP1(Point* p);
	void setP2(Point* p);
	void setP3(Point* p);

	Item* getItem() { return bezier; }

	QGraphicsItem* getModel();
};

#endif