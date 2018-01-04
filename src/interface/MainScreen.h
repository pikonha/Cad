#pragma once
#ifndef INCLUDED_MAINSCREEN_H
#define INCLUDED_MAINSCREEN_H

#include <QMainWindow>
#include "View.h"
#include "../data/Instruction.h"

class MainScreen : public QMainWindow
{
   Manager* manager;

public:
   /////////////////////////////////////////////////
   QMenuBar* navbar;
   QStatusBar* status;
   QTabWidget* tabs;

   /////////////////////////////////////////////////
   ~MainScreen();
	MainScreen(QMainWindow* parent = 0);

	void start();
   void setManager(Manager& m) { manager= &m; }
   Manager* getManager() const { return manager; }

   /////FILE
   void newFile();
	void loadFile();
	void saveFile();
   void closeFile();
   std::string getFileName(std::string path);
   void discardFile(int tabIndex);

   /////TABS
   void addTab(View* view, std::string name);
   void closeTab();
   void tabChangedSignal();

   /////DIALOGS
   void errorMessage();
   void successMessage();	
   int newFileDialog();
   void setStatusMessage(Instruction in);

   /////COMANDS
   void lineCommandSignal();
   void bezierCommandSignal();
   void archCommandSignal();
  
};

#endif