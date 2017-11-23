#pragma once
#ifndef INCLUDED_CMDSETSTATUSBAR_H
#define INCLUDED_CMDSETSTATUSBAR_H

#include "Cmd.h"

class CmdSetStatusBar :	public Cmd
{
public:
	CmdSetStatusBar();
	~CmdSetStatusBar();

	void execute(MainScreen* screen, MainView* view);
};

#endif
