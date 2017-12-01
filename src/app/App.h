#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

class Cmd;
class Data;
class Manager;
class CmdIdle;
class MainView;
class MainScreen;

class App
{
private:
	static App* app;

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
	Cmd* getCmd() { return cmd; }
	MainScreen* getScreen() { return screen; }
	MainView* getView() { return view; }
	Data* getData() { return data; }

	/////CMD	
	void setCmd(Cmd* command) { cmd = command; }
	void executeCmd();
	void deleteCmd() { delete cmd; }
	void setCmdIdle();

	void runCmd(Cmd* command);

	/////FILE
	void saveFile();
	void openFile();
};

#endif 