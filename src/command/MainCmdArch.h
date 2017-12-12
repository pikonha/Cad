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
	MainCmdArch(MainScreen* view) : MainCmd(view) { form = ARCH; }
	~MainCmdArch() {}
	
	void execute(Data& d, MainScreen& s);

	void setP1(Point* p);
	void setP2(Point* p);
	void setP3(Point* p);

	Item* getItem() { return arch; }

	QGraphicsItem* getModel();
};

#endif