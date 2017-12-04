#pragma once
#ifndef INCLUDED_MANAGER_H
#define INCLUDED_MANAGER_H
#include "Point.h"

class App;

class Manager
{
private:
	static Manager* manager;
	App* app;
	Manager(App* appl) { app = appl; }
	
public:
	static Manager* getInstance();
	~Manager() {}

	void mousePressEvent();
	void mouseReleaseEvent();
	void mouseMoveEvent();
	void wheelEvent();

	void newFile();
	void saveFile();
	void openFile();
	void clearFile();
	void closeFile();

	/////LINE
	void setLine();
	void setP1Line(Point p);
	void setP2Line(Point p);

	void setBezier();
	void setArch();

	void clearLastItem();
	void clearAllItems();
};

#endif