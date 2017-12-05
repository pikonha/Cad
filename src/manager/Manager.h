#pragma once
#ifndef INCLUDED_MANAGER_H
#define INCLUDED_MANAGER_H
#include "Point.h"

class App;
class MainCmd;

class Manager
{
private:
	static Manager* manager;
	App* app;
	Manager(App* appl) { app = appl; }
	
public:
	static Manager* getInstance();
	~Manager() {}

	/////MOUSE
	void mousePressEvent();
	void mouseReleaseEvent();
	void mouseMoveEvent();
	void wheelEvent();

	/////FILE
	void newFile();
	void saveFile();
	void openFile();
	void clearFile();
	void closeFile();

	/////DOMAIN
	void setLine();
	void setBezier();
	void setArch();

	/////ITEMS
	void clearLastItem();
	void clearAllItems();

	/////APP
	MainCmd* getMainCmd();
};

#endif