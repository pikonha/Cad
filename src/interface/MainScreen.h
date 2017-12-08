#pragma once
#ifndef INCLUDED_MAINSCREEN_H
#define INCLUDED_MAINSCREEN_H
#include <QMainWindow>
#include "MainView.h"

class MainScreen : public QMainWindow
{
private:
	MainView* view;
	QMenuBar* navbar;
	QStatusBar* status;

	Manager* manager;
public:	
	MainScreen(Manager* m, QMainWindow* parent = 0);
	~MainScreen();

	void start();

	void setZoom(double scale);

	void setTxtStatusBar();

	MainView* getView() { return view; }
};

#endif