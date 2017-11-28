#pragma once
#ifndef INCLUDED_CMDLOAD_H
#define INCLUDED_CMDLOAD_H

#include "Cmd.h"

class CmdLoad : public Cmd
{
public:
	CmdLoad(){}
	~CmdLoad(){}

	void execute(Data& d, MainScreen& s);
};

#endif
