#pragma once
#ifndef INCLUDED_MANAGER_H
#define INCLUDED_MANAGER_H

class MainCmd;
class MainScreen;
class Data;
class Cmd;
class View;
class Point;

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
	void mousePressEvent(Point mousePosition);
	void mouseReleaseEvent(Point mousePosition);
	void mouseMoveEvent(Point mousePosition);
	void wheelEvent();

	/////FILE
	void newFile();
	void saveFile();
	void openFile();
	void closeFile();
   void discardFile(int tab);
   void setCurrentFileByTab(View* v);

	/////DOMAIN
	void startLineCommand();
	void startBezierCommand();
	void startArchCommand();

	/////ITEMS
	void clearLastItem();
	void clearAllItems();
   void setZoom(int scale);

	/////CMD
	MainCmd& getCmdMain() { return *cmdmain; }
	Cmd& getCmd() { return *cmd; }

	void runCmd(Cmd* command);
   void closeTab(QWidget* widget);
};

#endif