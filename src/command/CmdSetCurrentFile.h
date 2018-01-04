#pragma once
#ifndef INCLUDED_CMDSETCURRENTFILE_H
#define INCLUDED_CMDSETCURRENTFILE_H

#include "Cmd.h"

class CmdSetCurrentFile : public Cmd
{
   File* file;

public:
   ~CmdSetCurrentFile() {}
   CmdSetCurrentFile(File* f) : file(f) {}
   

   void execute(Data& d,MainScreen& s);
};

#endif