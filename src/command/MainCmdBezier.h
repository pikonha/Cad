#pragma once
#ifndef INCLUDED_MAINCMDBEZIER_H
#define INCLUDED_MAINCMDBEZIER_H

#include "MainCmd.h"
#include "Point.h"
class Bezier;

class MainCmdBezier : public MainCmd
{
   Point p1,p2,p3;

   Bezier* bezier;
public:
   ~MainCmdBezier() {}
	MainCmdBezier(Data& d) : MainCmd(d), bezier(nullptr) { form = BEZIER; }	

   void setP1(const Point& p) override;
	void setP2(const Point& p) override;
	void setP3(const Point& p) override;

   Geometry* getNewGeometry() override;

   /////MOUSE EVENTS
   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p) override;
   void mouseMoveEvent(Point& p) override;
};

#endif