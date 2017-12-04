#pragma once
#ifndef INCLUDED_CMDPREPARELINE_H
#define INCLUDED_CMDPREPARELINE_H
#include "Cmd.h"

class CmdPrepareLine :	public Cmd
{
public:
	CmdPrepareLine(){}
	~CmdPrepareLine(){}

	void execute(Data& d, MainScreen& s);
};

#endif