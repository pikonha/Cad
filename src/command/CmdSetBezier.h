#pragma once
#ifndef INCLUDED_CMDSETBEZIER_H
#define INCLUDED_CMDSETBEZIER_H
#include "Cmd.h"

class CmdSetBezier : public Cmd
{
public:
	CmdSetBezier();
	~CmdSetBezier();

	void execute(Data& d, MainScreen& s);
};


#endif

