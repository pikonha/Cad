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
	
	void execute(Data& d, MainScreen& s) override;

   void setP1(const Point& p) override;
	void setP2(const Point& p) override;
	void setP3(const Point& p) override;

   Geometry& getGeometry() override { return *bezier; }

	QGraphicsItem* getQtGraphicGeo() override;

public:
   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p,Data& d) override;
   void mouseMoveEvent(Point& p) override;
};

#endif