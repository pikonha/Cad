#pragma once
#ifndef INCLUDED_CMDCLOSE_H
#define INCLUDED_CMDCLOSE_H

#include "Cmd.h"

class CmdClose : public Cmd
{
public:
	CmdClose();
	~CmdClose();

	void execute(MainScreen* screen);
};

#endif

