#pragma once
#ifndef INCLUDED_MANAGER_H
#define INCLUDED_MANAGER_H

class MainCmd;
class MainScreen;
class Data;
class Cmd;

class Manager
{
private:	
	MainScreen* screen;	
	MainCmd* cmdmain;
	Data* data;
	Cmd* cmd;	
public:
	Manager(Data* d);
	~Manager() {}

	void setScreen(MainScreen* s) { screen = s; }

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

	/////CMD
	MainCmd* getCmdMain() { return cmdmain; }
	Cmd* getCmd() { return cmd; }

	void runCmd(Cmd* command);
};

#endif