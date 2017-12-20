#pragma once
#ifndef INCLUDED_MAINCMDARCH_H
#define INCLUDED_MAINCMDARCH_H
#include "MainCmd.h"
#include "Arch.h"
class AuxLineModel;


class MainCmdArch :	public MainCmd
{
private:
	Arch* arch;

public:
	MainCmdArch(MainScreen& view) : MainCmd(view) { form = ARCH; }
	~MainCmdArch() {}
	
	void execute(Data& d, MainScreen& s) override;

	void setP1(const Point& p) override;
	void setP2(const Point& p) override;
	void setP3(const Point& p) override;

	Geometry& getGeometry() override { return *arch; }

	QGraphicsItem* getQtGraphicGeo() override;

public:
   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p,Data& d) override;
   void mouseMoveEvent(Point& p) override;
};

#endif