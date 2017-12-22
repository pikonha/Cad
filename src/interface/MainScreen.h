#pragma once
#ifndef INCLUDED_MAINSCREEN_H
#define INCLUDED_MAINSCREEN_H
#include <QMainWindow>
#include "MainView.h"
#include "Instruction.h"

class MainScreen : public QMainWindow
{
private:
	MainView* view;
	QMenuBar* navbar;

   QStatusBar* status;

	Manager* manager;
public:	
	MainScreen(QMainWindow* parent = 0);
	~MainScreen();

	void start();
   void setManager(Manager& m) { manager= &m; view->setManager(*manager); }

	void setZoom(double scale);

	MainView* getView() { return view; }

	void startLineCommand() const;
	void startBezierCommand() const;
	void startArchCommand() const;
	
	void openFile();
	void saveFile();
	void clearAllItems();
	void close();
	void clearLastItem();

   std::string getSaveFileName();
   std::string getLoadFileName();

   void errorMessage();
   void successMessage();	

   void setStatusMessage(Instruction in);
};

#endif