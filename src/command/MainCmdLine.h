#pragma once
#ifndef INCLUDED_MAINCMDLINE_H
#define INCLUDED_MAINCMDLINE_H

#include "MainCmd.h"
#include "Line.h"

class MainCmdLine :	public MainCmd
{
   Line* line;
public:
   ~MainCmdLine() {}
   MainCmdLine(Data& d) : MainCmd(d) { form = LINE; }
	
   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p) override;
   void mouseMoveEvent(Point& p) override;
};

#endif