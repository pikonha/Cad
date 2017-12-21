#pragma once
#ifndef INCLUDED_MAINCMDBEZIER_H
#define INCLUDED_MAINCMDBEZIER_H
#include "MainCmd.h"
#include "Bezier.h"

class MainCmdBezier : public MainCmd
{
private:
   Point p1,p2,p3;
public:
   ~MainCmdBezier() {}
	MainCmdBezier(MainScreen& view) : MainCmd(view) { form = BEZIER; }	
	
	void execute(Data& d, MainScreen& s) override;

   void setP1(const Point& p) override;
	void setP2(const Point& p) override;
	void setP3(const Point& p) override;

   Geometry* getNewGeometry() override { return new Bezier(p1,p2,p3); }

	QGraphicsItem* getQtGraphicGeo() override;

public:
   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p,Data& d) override;
   void mouseMoveEvent(Point& p) override;
};

#endif