#pragma once
#ifndef INCLUDED_CMD_H
#define INCLUDED_CMD_H
#include "Data.h"
#include "MainScreen.h"

class Cmd {
public:
	Cmd();
	virtual ~Cmd();

	virtual void execute(Data& d, MainScreen& s) = 0;
};

#endif