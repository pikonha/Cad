#pragma once
#ifndef INCLUDED_CMDDRAWBEZIER_H
#define INCLUDED_CMDDRAWBEZIER_H

#include "Cmd.h"

class CmdDrawBezier : public Cmd
{
public:
	CmdDrawBezier();
	~CmdDrawBezier();

	void execute(MainView* view);
};

#endif