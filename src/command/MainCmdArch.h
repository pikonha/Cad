#pragma once
#ifndef INCLUDED_MAINCMDARCH_H
#define INCLUDED_MAINCMDARCH_H

#include "MainCmd.h"
#include "Point.h"
class Arch;

class MainCmdArch :	public MainCmd
{
   Point p1,p2,p3;

   Arch* arch;
   Line* auxLine;
public:
   ~MainCmdArch() {}
   MainCmdArch(Data& d) : MainCmd(d), arch(nullptr), auxLine(nullptr) { form = ARCH; }

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