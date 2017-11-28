#pragma once
#ifndef INCLUDED_CMDCLEAR_H
#define INCLUDED_CMDCLEAR_H

#include "Cmd.h"

class CmdClear : public Cmd
{
public:
	CmdClear(){}
	~CmdClear(){}

	void execute(Data& d, MainScreen& s);
};

#endif