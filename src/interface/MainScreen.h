#pragma once
#ifndef INCLUDED_MAINSCREEN_H
#define INCLUDED_MAINSCREEN_H
#include <QMainWindow>
#include "View.h"
#include "Instruction.h"

class MainScreen : public QMainWindow
{
	QMenuBar* navbar;
   QStatusBar* status;
   QTabWidget* tabs;

	Manager* manager;

   std::vector<View*> views;
   
   View* currentView;
public:	
   ~MainScreen();
	MainScreen(QMainWindow* parent = 0);

	void start();
   void setManager(Manager& m) { manager= &m; }

	void startLineCommand() const;
	void startBezierCommand() const;
	void startArchCommand() const;
	
   void newFile();
	void openFile();
	void saveFile();
	void clearAllItems();
	void close();
	void clearLastItem();


   View& getCurrentView() const { return *currentView; }
   void setCurrentView(View* view) { currentView = view; }

   std::vector<View*>* getViews() { return &views; }

   std::string getSaveFileName();
   std::string getLoadFileName();

   void addTab(View* view, std::string name);
   void closeTab(int tab);

   void errorMessage();
   void successMessage();	

   void newFileDialog();

   void setStatusMessage(Instruction in);
};

#endif