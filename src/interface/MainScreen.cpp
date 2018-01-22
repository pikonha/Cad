#include "MainScreen.h"
#include <QMenuBar>
#include <QMenu>
#include <QIcon>
#include <QKeyEvent>
#include <QTabWidget>
#include <QDockWidget>
#include <QShortcut>
#include <QFileDialog>
#include <QStatusBar>
#include <QPushButton>
#include <QMessageBox>
#include "NewFileWidget.h"
#include "../manager/Manager.h"
#include <boost/filesystem/path.hpp>

#include <iostream>

MainScreen::~MainScreen()
{
   delete navbar;
   delete status;
   delete tabs;
}

MainScreen::MainScreen(QMainWindow* parent) :QMainWindow(parent),manager(nullptr)
{
   setMinimumSize(800,600);
   setWindowTitle(QString("AudacesCAD"));
   showMaximized();

   navbar = menuBar();
   navbar->setFixedWidth(1920);

   status = statusBar();
   status->setFixedWidth(1920);

   tabs = new QTabWidget(this);
   setCentralWidget(tabs);
   tabs->setTabsClosable(true);
   tabs->setMovable(true);
   tabs->setVisible(false);

   connect(tabs,&QTabWidget::tabCloseRequested,this,&MainScreen::closeTab);
   connect(tabs,&QTabWidget::tabBarClicked,this,&MainScreen::tabChangedSignal);

   slider = new QSlider(Qt::Horizontal);
   slider->setValue(10);
   slider->setMaximum(31);
   slider->setMinimum(1);
   slider->setFixedSize(200,20);
   status->addPermanentWidget(slider);
   connect(slider,&QSlider::sliderMoved,this,&MainScreen::sliderChange);

   bottomBar = new NewFileWidget(this);
   addToolBar(Qt::BottomToolBarArea,bottomBar);
   connect(bottomBar->confirm,&QPushButton::pressed,this,&MainScreen::newFile);
   connect(bottomBar->cancel,&QPushButton::pressed,this,&MainScreen::closeBottomBar);

   QMenu* file = new QMenu("File");
   QAction* line = new QAction("Line");
   QAction* bezier = new QAction("Bezier");
   QAction* arc = new QAction("Arc");

   QAction* newFile = new QAction("New");
   QAction* open = new QAction("Open");
   QAction* save = new QAction("Save");
   QAction* clear = new QAction("Clear");
   QAction* close = new QAction("Close");

   file->addAction(newFile);
   file->addAction(open);
   file->addAction(save);
   file->addAction(clear);
   file->addAction(close);

   QIcon* iconNew = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/new.png");
   QIcon* iconSave = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/save.png");
   QIcon* iconClear = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/clean.png");
   QIcon* iconClose = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/close.png");
   QIcon* iconOpen = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/open.png");

   newFile->setIcon(*iconNew);
   open->setIcon(*iconOpen);
   save->setIcon(*iconSave);
   clear->setIcon(*iconClear);
   close->setIcon(*iconClose);

   navbar->addMenu(file);
   navbar->addAction(line);
   navbar->addAction(bezier);
   navbar->addAction(arc);

   connect(line,&QAction::triggered,this,&MainScreen::lineCommandSignal);
   connect(bezier,&QAction::triggered,this,&MainScreen::bezierCommandSignal);
   connect(arc,&QAction::triggered,this,&MainScreen::archCommandSignal);

   connect(newFile,&QAction::triggered,this,&MainScreen::openBottomBar);
   connect(open,&QAction::triggered,this,&MainScreen::loadFile);
   connect(save,&QAction::triggered,this,&MainScreen::saveFile);
   connect(clear,&QAction::triggered,this,&MainScreen::clearTab);
   connect(close,&QAction::triggered,this,&MainScreen::closeFile);

   connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N),this),&QShortcut::activated,this,&MainScreen::openBottomBar);
   connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_W),this),&QShortcut::activated,this,&MainScreen::closeTab);
   connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_O),this),&QShortcut::activated,this,&MainScreen::loadFile);
}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::start()
{
   show();
}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::newFile()
{
   manager->newFile();
   closeBottomBar();
}

void MainScreen::loadFile()
{
   manager->openFile();
}

void MainScreen::saveFile()
{
   manager->saveFile();
}

void MainScreen::discardFile(int tabIndex)
{
   manager->discardFile(tabIndex);
}

View* MainScreen::createView()
{
   return new View(manager,this);
}

void MainScreen::closeFile()
{
   manager->closeFile();
}

void MainScreen::openBottomBar()
{
   bottomBar->setVisible(true);
   bottomBar->lineEdit->setFocus();
}

void MainScreen::closeBottomBar()
{
   bottomBar->setVisible(false);
   bottomBar->clearEdit();
}

std::string MainScreen::getTextFromBottomBar()
{
   return bottomBar->getText();
}

////////////////////////////////////////////////////////////////////////////////

std::string MainScreen::getFileName(std::string pathFile)
{
   boost::filesystem::path path(pathFile);

   std::string arq = path.stem().string();

   if (arq == ".")
      arq = "";

   return arq;
}

void MainScreen::addTab(View* view,std::string name)
{
   tabs->insertTab(0,view,QString::fromStdString(name));
   tabs->setCurrentIndex(0);

   tabs->show();
}

void MainScreen::tabChangedSignal(int index)
{
   manager->setCurrentFileByTab(dynamic_cast<View*>(tabs->widget(index)));
}

void MainScreen::clearTab()
{
   manager->clearAllItems();
}

void MainScreen::closeTab()
{
   manager->closeTab(tabs->widget(tabs->currentIndex()));
}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::errorMessage()
{
   QMessageBox::warning(this,tr("Fatal error"),tr("An error occurred while processing your request."),QMessageBox::Ok);
}

void MainScreen::successMessage()
{
   QMessageBox::information(this,tr("Good news"),tr("Successful request."),QMessageBox::Ok);
}

void MainScreen::closeTabDialog()
{
   View* view = dynamic_cast<View*>(tabs->widget(tabs->tabPosition()));

   if (view) {
      QMessageBox warning;
      warning.setText("The document has been modified.");
      warning.setInformativeText("Do you want to save your changes?");
      warning.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
      warning.setDefaultButton(QMessageBox::Save);
      warning.setIcon(QMessageBox::Question);

      const int option = warning.exec();

      switch (option)
      {
      case QMessageBox::Save: saveFile(); break;
      case QMessageBox::Discard: discardFile(tabs->tabPosition()); break;
      }

      if (tabs->count() == 0)
         tabs->setVisible(false);
   }
}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::setStatusMessage(Instruction in)
{
   switch (in)
   {
   case 0: status->showMessage("Waiting for a click on the screen."); break;
   case 1: status->showMessage("Keep pressed and move the cursor. (Release to finish)"); break;
   case 2: status->showMessage("Move the cursor to set the final draw."); break;
   case 3: status->showMessage("Click to set the draw's length."); break;
   }
}

void MainScreen::lineCommandSignal()
{
   manager->startLineCommand();
}

void MainScreen::bezierCommandSignal()
{
   manager->startBezierCommand();
}

void MainScreen::archCommandSignal()
{
   manager->startArchCommand();
}

void MainScreen::sliderChange()
{
   if (tabs->count() > 0)
   {
      int percent = slider->value() * 10;
      manager->setZoom(percent);
   }
}

