#pragma once
#ifndef INCLUDED_CMDSETLINE_H
#define INCLUDED_CMDSETLINE_H
#include "Cmd.h"

class CmdSetLine : public Cmd
{
public:
	CmdSetLine() {}
	~CmdSetLine() {}

	void execute(Data& d, MainScreen& s);
};

#endif