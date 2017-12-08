#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

class Data;
class Manager;
class MainView;
class MainScreen;

class App
{
private:
	static App* app;

	Data* data;
	MainView* view;
	Manager* manager;
	MainScreen* screen;	

	App();
public:
	~App();

	/////SETUP
	static App* getInstance();
	int start(int argc, char** argv);
};

#endif 