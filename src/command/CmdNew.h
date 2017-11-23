#pragma once
#ifndef INCLUDED_CMDNEW_H
#define INCLUDED_CMDNEW_H

#include "Cmd.h"

class CmdNew : public Cmd
{
public:
	CmdNew();
	~CmdNew();

	void execute(MainScreen* screen, MainView* view);
};

#endif
