#pragma once
#ifndef INCLUDED_MAINCMDARCH_H
#define INCLUDED_MAINCMDARCH_H

#include "MainCmd.h"
#include "Arch.h"

class MainCmdArch :	public MainCmd
{
   Point p1,p2,p3;

   Arch* arch;
public:
   ~MainCmdArch() {}
   MainCmdArch(View& view, File& f) : MainCmd(view, f) { form = ARCH; }

	void setP1(const Point& p) override;
	void setP2(const Point& p) override;
	void setP3(const Point& p) override;

   Geometry* getNewGeometry() override;

   /////MOUSE EVENTS
   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p,Data& d) override;
   void mouseMoveEvent(Point& p) override;
};

#endif