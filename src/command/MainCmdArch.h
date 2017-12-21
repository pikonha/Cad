#pragma once
#ifndef INCLUDED_MAINCMDARCH_H
#define INCLUDED_MAINCMDARCH_H
#include "MainCmd.h"
#include "Arch.h"
class AuxLineModel;


class MainCmdArch :	public MainCmd
{
   Point p1,p2,p3;
public:
   ~MainCmdArch() {}
   MainCmdArch(MainScreen& view) : MainCmd(view) { form = ARCH; }
	
	void execute(Data& d, MainScreen& s) override;

	void setP1(const Point& p) override;
	void setP2(const Point& p) override;
	void setP3(const Point& p) override;

	Geometry* getNewGeometry() override { return new Arch(p1,p2,p3); }

	QGraphicsItem* getQtGraphicGeo() override;

public:
   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p,Data& d) override;
   void mouseMoveEvent(Point& p) override;
};

#endif