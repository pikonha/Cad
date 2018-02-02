#include <QMenu>
#include <QIcon>
#include <QMenuBar>
#include <windows.h>
#include <QKeyEvent>
#include <QShortcut>
#include <QStatusBar>
#include <QFileDialog>
#include <QPushButton>
#include <QMessageBox>
#include "MainScreen.h"
#include "NewFileWidget.h"
#include "../manager/Manager.h"


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

   setTabs();
   setSlider();
   setStatusBar();
   setBottomBar();
   setNavbar();
   setCss();
   setShortCuts();

   setContextMenuPolicy(Qt::NoContextMenu);
}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::start()
{
   show();
}

void MainScreen::setTabs()
{
   tabs = new QTabWidget(this);
   setCentralWidget(tabs);
   tabs->setTabsClosable(true);
   tabs->setMovable(true);
   tabs->setVisible(false);

   connect(tabs,&QTabWidget::tabCloseRequested,this,&MainScreen::closeTab);
   connect(tabs,&QTabWidget::tabBarClicked,this,&MainScreen::tabChangedSignal);
}

void MainScreen::setNavbar()
{
   navbar = menuBar();
   navbar->setFixedWidth(GetSystemMetrics(SM_CXSCREEN));

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

   QIcon* iconNew = new QIcon(":/new");
   QIcon* iconSave = new QIcon(":/save");
   QIcon* iconClear = new QIcon(":/clean");
   QIcon* iconClose = new QIcon(":/close");
   QIcon* iconOpen = new QIcon(":/open");

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
}

void MainScreen::setStatusBar()
{
   status = statusBar();
   status->setMaximumWidth(GetSystemMetrics(SM_CXSCREEN));
   status->addPermanentWidget(slider);
}

void MainScreen::setSlider()
{
   slider = new QSlider(Qt::Horizontal);
   slider->setValue(10);
   slider->setMaximum(20);
   slider->setMinimum(0);
   slider->setFixedSize(200,20);

   connect(slider,&QSlider::sliderMoved,this,&MainScreen::sliderChange);
}

void MainScreen::setBottomBar()
{
   bottomBar = new NewFileWidget(this);
   addToolBar(Qt::BottomToolBarArea,bottomBar);

   connect(bottomBar->confirm,&QPushButton::pressed,this,&MainScreen::newFile);
   connect(bottomBar->cancel,&QPushButton::pressed,this,&MainScreen::closeBottomBar);
}

void MainScreen::setCss()
{
   setStyleSheet("QMainWindow {background-color: #848484; }  QMenuBar::item:selected{color: black; background:white;}");
   navbar->setStyleSheet("background-color: black; color: white; padding:0px;");
   status->setStyleSheet("background: black; color: white;");
   slider->setStyleSheet("QSlider{background:black;}QSlider::groove:horizontal{border: 1px solid #999999; height: 8px;background: white; margin: 2px 0;} QSlider::handle:horizontal{background: black; border: 1px solid #5c5c5c; width: 18px; margin: -2px 0; border - radius: 3px;}");
   bottomBar->setStyleSheet("background: black; color:white;");
}

void MainScreen::setShortCuts()
{
   connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N),this),&QShortcut::activated,this,&MainScreen::openBottomBar);
   connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_W),this),&QShortcut::activated,this,&MainScreen::closeTab);
   connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_O),this),&QShortcut::activated,this,&MainScreen::loadFile);

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
   QFileInfo fileInfo(QString::fromStdString(pathFile));
   QString arq = fileInfo.baseName();

   if (arq == ".")
      arq = "";

   return arq.toLocal8Bit().constData();
}

void MainScreen::addTab(View* view,std::string name)
{
   tabs->insertTab(0,view,QString::fromStdString(name));
   tabs->setCurrentIndex(0);
   tabs->setUsesScrollButtons(true);

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

void MainScreen::closeTab(int index)
{
   manager->closeTab(tabs->widget(index));
   //manager->closeTab(tabs->widget(tabs->currentIndex()));
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
      int percent = (slider->value() + 1) * 10;
      manager->setZoom(percent);
   }
}



void MainScreen::paintEvent(QPaintEvent* event)
{
   navbar->setMaximumWidth(GetSystemMetrics(SM_CXSCREEN));
   status->setMaximumWidth(GetSystemMetrics(SM_CXSCREEN));
}

