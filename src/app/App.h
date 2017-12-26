#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

class Data;
class Manager;
class MainScreen;

class App
{
	static App* app;

	Data* data;
	Manager* manager;
	MainScreen* screen;	

	App();
public:
	~App();

	/////SETUP
	static App& getInstance();
	int start(int argc, char** argv);

	Manager& getManager() const { return *manager; }
   MainScreen& getScreen() const { return *screen; }
};

#endif 