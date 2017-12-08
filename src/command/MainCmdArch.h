#pragma once
#ifndef INCLUDED_MAINCMDARCH_H
#define INCLUDED_MAINCMDARCH_H
#include "MainCmd.h"
#include "Arch.h"
class AuxLineModel;


class MainCmdArch :	public MainCmd
{
private:
	Arch* arch;

public:
	MainCmdArch(Data* d, MainView* s, Form f) : MainCmd(d, s, f) {}
	~MainCmdArch() {}
	
	void execute();

	void setP1(Point p);
	void setP2(Point p);
	void setP3(Point p);

	Item* getItem() { return arch; }

	QGraphicsItem* getModel();
};

#endif