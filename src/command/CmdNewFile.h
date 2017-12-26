#pragma once
#ifndef INCLUDED_CMDNEWFILE_H
#define INCLUDED_CMDNEWFILE_H

#include "Cmd.h"

class CmdNewFile : public Cmd
{
public:
	CmdNewFile(){}
	~CmdNewFile(){}

	void execute(Data& d, MainScreen& s) override;
};

#endif
