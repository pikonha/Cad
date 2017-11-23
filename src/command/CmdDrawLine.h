#pragma once
#ifndef INCLUDED_CMDDRAWLINE_H
#define INCLUDED_CMDDRAWLINE_H

#include "Cmd.h"

class CmdDrawLine :	public Cmd
{
public:
	CmdDrawLine();
	~CmdDrawLine();

	void execute(MainView* view);
};

#endif
