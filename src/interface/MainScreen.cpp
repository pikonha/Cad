#include "MainScreen.h"
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QIcon>
#include <QShortcut>
#include <QFileDialog>
#include <QStatusBar>
#include "../manager/Manager.h"

MainScreen::~MainScreen()
{
   delete view;
}

MainScreen::MainScreen(QMainWindow* parent) : QMainWindow(parent), manager(nullptr)
{
	setFixedSize(1920, 1020);
	showMaximized();

	view = new MainView();

	navbar = menuBar();	

   status = statusBar();
   status->show();

	QMenu* file = new QMenu("File");
	QAction* line = new QAction("Line");
	QAction* bezier = new QAction("Bezier");
	QAction* arc = new QAction("Arc");	
	
	QAction* open = new QAction("Open");
	QAction* save = new QAction("Save");
	QAction* clear = new QAction("Clear");
	QAction* close = new QAction("Close");

	file->addAction(open);
	file->addAction(save);
	file->addAction(clear);
	file->addAction(close);

	QIcon* iconSave = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/save.png");
	QIcon* iconClear = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/clean.png");
	QIcon* iconClose = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/close.png");
	QIcon* iconOpen = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/open.png");

	open->setIcon(*iconOpen);
	save->setIcon(*iconSave);
	clear->setIcon(*iconClear);
	close->setIcon(*iconClose);

	navbar->addMenu(file);
	navbar->addAction(line);
	navbar->addAction(bezier);
	navbar->addAction(arc);
	
	setCentralWidget(view);

	connect(line, &QAction::triggered, this, &MainScreen::startLineCommand);
	connect(bezier, &QAction::triggered, this, &MainScreen::startBezierCommand);
	connect(arc, &QAction::triggered, this, &MainScreen::startArchCommand);	

	connect(open, &QAction::triggered, this,  &MainScreen::openFile);
	connect(save, &QAction::triggered, this,  &MainScreen::saveFile);
	connect(clear, &QAction::triggered, this, &MainScreen::clearAllItems);
	connect(close, &QAction::triggered, this, &MainScreen::close);

	QShortcut* undone = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
	connect(undone, &QShortcut::activated, this, &MainScreen::clearLastItem);

   QShortcut* saveSc = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S),this);
   connect(saveSc,&QShortcut::activated,this,&MainScreen::saveFile);
}

void MainScreen::start()
{
	show();
}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::startLineCommand() const
{
   manager->startLineCommand();
}

void MainScreen::startBezierCommand() const
{
   manager->startBezierCommand();
}

void MainScreen::startArchCommand() const
{
   manager->startArchCommand();
}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::setZoom(double scale)
{
	
}

void MainScreen::openFile()
{
   manager->openFile();
}

void MainScreen::saveFile()
{
   manager->saveFile();
}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::clearAllItems()
{
	manager->clearAllItems();
}

void MainScreen::close()
{
   manager->closeFile();
   QMainWindow::close();
}

void MainScreen::clearLastItem()
{
	manager->clearLastItem();
}

std::string MainScreen::getSaveFileName()
{
   return QFileDialog::getSaveFileName(view,QString("Save File"),"",QString("Dat files (*.dat)")).toStdString();

}

std::string MainScreen::getLoadFileName()
{
   return QFileDialog::getOpenFileName(view,QString("Open file"),"",QString("Dat files (*.dat)")).toStdString();
}

void MainScreen::errorMessage()
{
}

void MainScreen::successMessage()
{
}

void MainScreen::setStatusMessage(Instruction in)
{
   switch (in)
   {
   case 0: status->showMessage("Waiting for a click on the screen."); break;
   case 1: status->showMessage("Keep pressed and move the cursor. (Release to finish)"); break;
   case 2: status->showMessage("Click to set the draw's length."); break;
   }
}
