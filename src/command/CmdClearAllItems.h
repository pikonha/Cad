#pragma once
#ifndef INCLUDED_CMDCLEARALLITEMS_H
#define INCLUDED_CMDCLEARALLITEMS_H
#include "Cmd.h"

class CmdClearAllItems : public Cmd
{
public:
	CmdClearAllItems() {}
	~CmdClearAllItems(){}

	void execute(Data& d, MainScreen& s);
};

#endif