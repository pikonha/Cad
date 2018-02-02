#pragma once
#ifndef INCLUDED_MAINSCREEN_H
#define INCLUDED_MAINSCREEN_H

#include <QMainWindow>
#include "View.h"
#include "../data/Instruction.h"
#include <QSlider>
class NewFileWidget;


class MainScreen : public QMainWindow
{
   Manager* manager;

public:
   /////////////////////////////////////////////////
   QMenuBar* navbar;
   QStatusBar* status;
   QTabWidget* tabs;
   QSlider* slider;
   NewFileWidget* bottomBar;

   /////////////////////////////////////////////////
   ~MainScreen();
	MainScreen(QMainWindow* parent = 0);

	void start();
   void setManager(Manager& m) { manager= &m; }
   Manager* getManager() const { return manager; }

   void setTabs();
   void setNavbar();
   void setStatusBar();
   void setSlider();
   void setBottomBar();
   void setCss();
   void setShortCuts();  

   /////FILE
   void newFile();
	void loadFile();
	void saveFile();
   void closeFile();
   void openBottomBar();
   void closeBottomBar();
   std::string getTextFromBottomBar();
   std::string getFileName(std::string path);
   void discardFile(int tabIndex);   
   View* createView();

   /////TABS
   void addTab(View* view, std::string name);
   void closeTabDialog();
   void tabChangedSignal(int index);
   void clearTab();
   void closeTab();

   /////DIALOGS
   void errorMessage();
   void successMessage();	
   void setStatusMessage(Instruction in);

   /////COMANDS
   void lineCommandSignal();
   void bezierCommandSignal();
   void archCommandSignal();
   void sliderChange();

protected:
   void paintEvent(QPaintEvent* event) override;
   void wheelEvent(QWheelEvent* event) override;
};



#endif