#pragma once
#ifndef INCLUDED_MAINCMDLINE_H
#define INCLUDED_MAINCMDLINE_H

#include "MainCmd.h"
#include "Line.h"

class MainCmdLine :	public MainCmd
{
   Point p1,p2;

   Line* line;
public:
   ~MainCmdLine() {}
   MainCmdLine(Data& d) : MainCmd(d), line(nullptr) { form = LINE; }
	
	void setP1(const Point& p) override;
	void setP2(const Point& p) override;

   Geometry* getNewGeometry() override;

   /////MOUSE EVENTS
   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p) override;
   void mouseMoveEvent(Point& p) override;
};

#endif