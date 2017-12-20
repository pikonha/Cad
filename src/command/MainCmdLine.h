#pragma once
#ifndef INCLUDED_MAINCMDLINE_H
#define INCLUDED_MAINCMDLINE_H
#include "MainCmd.h"

class Line;

class MainCmdLine :	public MainCmd
{
private:
	Line* line;
public:
	MainCmdLine(MainScreen& view) : MainCmd(view) { form = LINE; }
	~MainCmdLine() {}

	void execute(Data& d, MainScreen& s) override;
	
	void setP1(const Point& p) override;
	void setP2(const Point& p) override;

   Geometry& getGeometry() override { return *line; }

	QGraphicsItem* getQtGraphicGeo() override;

public :
   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p,Data& d) override;
   void mouseMoveEvent(Point& p) override;
};

#endif