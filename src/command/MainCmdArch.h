#pragma once
#ifndef INCLUDED_MAINCMDARCH_H
#define INCLUDED_MAINCMDARCH_H

#include "MainCmd.h"
#include "Arch.h"

class MainCmdArch :	public MainCmd
{
   Arch arch;
   Line* auxLine;
public:
   ~MainCmdArch() {}
   MainCmdArch(Data& d) : MainCmd(d) { form = ARCH; auxLine = new Line(); }

   void mousePressEvent(Point& p) override;
   void mouseReleaseEvent(Point& p) override;
   void mouseMoveEvent(Point& p) override;
};

#endif