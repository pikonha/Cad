#pragma once
#ifndef INCLUDED_CMDSETZOOM_H
#define INCLUDED_CMDSETZOOM_H

#include "Cmd.h"

class CmdSetZoom : public Cmd
{
   int scale;

public:
   CmdSetZoom(int s ) : scale(s){}
   ~CmdSetZoom() {}

   void execute(Data& d, MainScreen& s) override;
};

#endif