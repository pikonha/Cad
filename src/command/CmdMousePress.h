#pragma once
#ifndef INCLUDED_CMDMOUSEPRESS_H
#define INCLUDED_CMDMOUSEPRESS_H

#include "Cmd.h"

class CmdMousePress : public Cmd
{
public:
	CmdMousePress();
	~CmdMousePress();

	void execute(MainView* view);
};

#endif

