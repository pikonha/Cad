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
	static MainScreen* main;
	MainView* view;
	QMenuBar* navbar;
	QStatusBar* status;

	MainScreen(QMainWindow* parent = 0);
public:	
	virtual ~MainScreen();

	static MainScreen* getInstance();

	int start(QApplication* app);

	void setZoom(double scale);

	void setTxtStatusBar();
};

#endif