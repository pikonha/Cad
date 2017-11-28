#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#include "../interface/MainScreen.h"
#include "../command/Cmd.h"
#include "../domain/Data.h"
#include "../command/CmdIdle.h"

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
	void executeCmd() { cmd->execute(*data, *screen);  }
	void deleteCmd() { delete cmd; }
	void setCmdIdle() { cmd = new CmdIdle(); }

	void runCmd(Cmd* command);

	/////FILE
	void saveFile();
	void openFile();
};

#endif 