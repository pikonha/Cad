#pragma once
#ifndef INCLUDED_CMD_H
#define INCLUDED_CMD_H

class MainScreen;
class MainView;
class Persist;
class UserI;

class Cmd {
public:
	Cmd();
	virtual ~Cmd();

	virtual void execute(MainScreen* screen = 0, MainView* view = 0, Persist* persist = 0, UserI* user = 0) = 0;
};

#endif