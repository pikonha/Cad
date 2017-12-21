#pragma once
#ifndef INCLUDED_MAINCMDLINE_H
#define INCLUDED_MAINCMDLINE_H

#include "MainCmd.h"
#include "Line.h"

class MainCmdLine :	public MainCmd
{
private:
   Point p1,p2;

public:
   ~MainCmdLine() {}
   MainCmdLine(MainScreen& view) : MainCmd(view) { form = LINE; }

	void execute(Data& d, MainScreen& s) override;
	
	void setP1(const Point& p) override;
	void setP2(const Point& p) override;

   Geometry* getNewGeometry() override { return new Line(p1,p2); }

	QGraphicsItem* getQtGraphicGeo() override;

public :
   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p,Data& d) override;
   void mouseMoveEvent(Point& p) override;
};

#endif