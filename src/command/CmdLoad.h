#pragma once
#ifndef INCLUDED_CMDLOAD_H
#define INCLUDED_CMDLOAD_H

#include "Cmd.h"
#include <fstream>

class CmdLoad : public Cmd
{
   void loadLine(std::ifstream& stream);
   void loadBezier(std::ifstream& stream);
   void loadArch(std::ifstream& stream);
public:
	CmdLoad(){}
	~CmdLoad(){}

	void execute(Data& d, MainScreen& s);
};

#endif
