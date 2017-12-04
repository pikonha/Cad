#pragma once
#ifndef INCLUDED_MAINCMDARCH_H
#define INCLUDED_MAINCMDARCH_H
#include "MainCmd.h"

class Arch;

class MainCmdArch :	public MainCmd
{
private:
	Arch* arch;
	bool drawingArch;

public:
	MainCmdArch(Data* d, MainScreen* s) : MainCmd(d, s) { drawingArch = false; }
	~MainCmdArch() {}
	
	void execute();

	void setP1(Point p);
	void setP2(Point p);
	void setP3(Point p);

	void draw();

	void pressMouse();
	void moveMouse();
	void releaseMouse();	
};

#endif