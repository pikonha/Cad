#pragma once
#ifndef INCLUDED_CMDDRAWARCH_H
#define INCLUDED_CMDDRAWARCH_H

#include "Cmd.h"

class CmdDrawArch :	public Cmd
{
public:
	CmdDrawArch();
	~CmdDrawArch();

	void execute(MainView* view);
};

#endif