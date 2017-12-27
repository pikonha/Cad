#pragma once
#ifndef INCLUDED_MANAGER_H
#define INCLUDED_MANAGER_H

class MainCmd;
class MainScreen;
class Data;
class Cmd;

class Manager
{
	Data& data;
	MainScreen& screen;

	Cmd* cmd;
	MainCmd* cmdmain;
public:
	Manager(Data& d, MainScreen& s);
   ~Manager();

	/////MOUSE
	void mousePressEvent();
	void mouseReleaseEvent();
	void mouseMoveEvent();
	void wheelEvent();

	/////FILE
	void newFile();
	void saveFile();
	void openFile();
	void closeFile();
   void discardFile(int tab);

	/////DOMAIN
	void startLineCommand();
	void startBezierCommand();
	void startArchCommand();

	/////ITEMS
	void clearLastItem();
	void clearAllItems();

	/////CMD
	MainCmd& getCmdMain() { return *cmdmain; }
	Cmd& getCmd() { return *cmd; }

	void runCmd(Cmd* command);
   
};

#endif