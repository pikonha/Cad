#pragma once
#ifndef INCLUDED_CMDWHEELEVENT_H
#define INCLUDED_CMDWHEELEVENT_H

#include "Cmd.h"

class CmdWheelEvent : public Cmd
{
public:
	CmdWheelEvent() {}
	~CmdWheelEvent() {}

	void execute(Data& d, MainScreen& s);
};

#endif

