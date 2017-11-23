#pragma once
#ifndef INCLUDED_CMDZOOM_H
#define INCLUDED_CMDZOOM_H

#include "Cmd.h"

class CmdZoom :	public Cmd
{
public:
	CmdZoom();
	~CmdZoom();

	void execute(MainScreen* screen, MainView* view);
};

#endif

