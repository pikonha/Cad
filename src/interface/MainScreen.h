#pragma once
#ifndef INCLUDED_MAINSCREEN_H
#define INCLUDED_MAINSCREEN_H
#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <QMainWindow>
#include "MainView.h"

class MainScreen : public QMainWindow
{
	Q_OBJECT
private:
	MainView* view;
	QMenuBar* navbar;
	QStatusBar* status;
	
public:	
	MainScreen(QMainWindow* parent = 0);
	virtual ~MainScreen();

	int start(QApplication* app);

	void setZoom(double scale);

	void setTxtStatusBar();

	MainView* getView() { return view; }
};

#endif