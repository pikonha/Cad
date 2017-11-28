#pragma once
#ifndef INCLUDED_CMDMOUSECLICK_H
#define INCLUDED_CMDMOUSECLICK_H

#include "Cmd.h"

class CmdMouseClick : public Cmd
{
public:
	CmdMouseClick() {}
	~CmdMouseClick() {}

	void execute(Data& d, MainScreen& s);
};

#endif