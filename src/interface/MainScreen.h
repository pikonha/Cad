#pragma once
#ifndef INCLUDED_MAINSCREEN_H
#define INCLUDED_MAINSCREEN_H
#include <QMainWindow>
#include "View.h"
#include "Instruction.h"

class MainScreen : public QMainWindow
{
   Manager* manager;
   QPainter& painter;

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
   void close();

   int newFileDialog();
   void discardFile(int tabIndex);

   void clearAllItems();
	void clearLastItem();

   View& getCurrentView() const { return *currentView; }
   void setCurrentView(View* view) { currentView = view; }

   std::vector<View*>* getViews() { return &views; }

   std::string getSavePath();
   std::string getLoadPath();

   std::string getFileName(std::string path);

   void addTab(View* view, std::string name);
   void closeTab();

   void errorMessage();
   void successMessage();	
   
   void deleteView(View* view);

   void setStatusMessage(Instruction in);

   QPainter& getPainter() const { return painter; }

public:
   QMenuBar* navbar;
   QStatusBar* status;
   QTabWidget* tabs;
};

#endif