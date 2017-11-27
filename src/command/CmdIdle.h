#pragma once
#ifndef INCLUDED_CMDIDLE_H
#define INCLUDED_CMDIDLE_H

#include "Cmd.h"

class CmdIdle : public Cmd
{
public:
	CmdIdle() {}
	~CmdIdle() {}
	
	void execute() {}
};


#endif