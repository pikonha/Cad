#pragma once
#ifndef INCLUDED_CMDMOUSEMOVE_H
#define INCLUDED_CMDMOUSEMOVE_H

#include "Cmd.h"

class CmdMouseMove : public Cmd
{
public:
	CmdMouseMove();
	~CmdMouseMove();

	void execute(MainView* view);
};

#endif
