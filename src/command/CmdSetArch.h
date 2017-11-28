#pragma once
#ifndef INCLUDED_CMDSETARCH_H
#define INCLUDED_CMDSETARCH_H
#include "Cmd.h"

class CmdSetArch : public Cmd
{
public:
	CmdSetArch();
	~CmdSetArch();

	void execute(Data& d, MainScreen& s);
};

#endif

