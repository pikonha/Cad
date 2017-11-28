#pragma once
#include "Cmd.h"

class CmdClearLastItem : public Cmd
{
public:
	CmdClearLastItem() {}
	~CmdClearLastItem() {}

	void execute(Data& d, MainScreen& s);
};

