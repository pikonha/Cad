#pragma once
#ifndef INCLUDED_MAINCMDBEZIER_H
#define INCLUDED_MAINCMDBEZIER_H

#include "MainCmd.h"
#include "Point.h"
#include "Bezier.h"

class MainCmdBezier : public MainCmd
{
   Bezier* bezier;
   Line* auxLine;
public:
   ~MainCmdBezier() {}
   MainCmdBezier(Data& d) : MainCmd(d) { form = BEZIER; auxLine = new Line(); }

   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p) override;
   void mouseMoveEvent(Point& p) override;
};

#endif