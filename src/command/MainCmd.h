#pragma once
#ifndef INCLUDED_MAINCMD_H
#define INCLUDED_MAINCMD_H
#include "Data.h"
#include "MainScreen.h"
#include "Item.h"

class MainCmd
{
protected:
	Data* data;
	MainScreen* screen;
public:
	MainCmd(Data* d, MainScreen* s) { data = d; screen = s; }
	~MainCmd() {}

	virtual void execute() = 0;

	virtual void setP1() = 0;
	virtual void setP2() = 0;
	
	virtual void draw() = 0;

	virtual void pressMouse() = 0;
	virtual void moveMouse() = 0;
	virtual void releaseMouse() = 0;
};

#endif