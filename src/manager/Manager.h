#pragma once
#ifndef INCLUDED_MANAGER_H
#define INCLUDED_MANAGER_H

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

	void newFile();
	void saveFile();
	void openFile();
	void clearFile();
	void closeFile();

	void setLine();
	void setBezier();
	void setArch();

	void clearLastItem();
	void clearAllItems();
};

#endif