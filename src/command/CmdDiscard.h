#pragma once
#ifndef INCLUDED_CMDDISCARD_H
#define INCLUDED_CMDDISCARD_H

#include "Cmd.h"

class CmdDiscard : public Cmd
{
   int tab;
public:
   ~CmdDiscard() {}
   CmdDiscard(const int tabIndex) : tab(tabIndex) {}
   
   void execute(Data& d,MainScreen& s) override;
};

#endif