#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

class MainCmd;
class Cmd;
class Data;
class Manager;
class MainView;
class MainScreen;

class App
{
private:
	static App* app;

	MainCmd* cmdmain;
	Cmd* cmd;

	MainScreen* screen;	
	MainView* view;
	Data* data;
	Manager* manager;

	App();
public:
	~App();

	/////SETUP
	static App* getInstance();
	int start(int argc, char** argv);

	/////GETTERS
	MainCmd* getCmdMain() { return cmdmain; }
	Cmd* getCmd() { return cmd; }
	MainScreen* getScreen() { return screen; }
	MainView* getView() { return view; }
	Data* getData() { return data; }

	/////CMD	
	void setCmdMain(MainCmd* cmd);

	void runCmd(Cmd* command);

	void setCmd(Cmd* cmmd) { cmd = cmmd; }
	void executeCmd();
	void deleteCmd() { delete cmd; }
	void setCmdIdle();

};

#endif 