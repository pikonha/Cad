#pragma once
#ifndef INCLUDED_CMDMOUSERELEASE_H
#define INCLUDED_CMDMOUSERELEASE_H

#include "Cmd.h"

class CmdMouseRelease : public Cmd
{
public:
	CmdMouseRelease() {}
	~CmdMouseRelease() {}

	void execute(Data& d, MainScreen& s);
};

#endif

