#include "MainScreen.h"
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QIcon>
#include <QShortcut>

MainScreen::~MainScreen()
{
   delete view;
}

MainScreen::MainScreen(QMainWindow* parent) : manager(nullptr), QMainWindow(parent)
{
	setFixedSize(1920, 1020);
	showMaximized();

	view = new MainView();

	navbar = menuBar();	

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

}

void MainScreen::saveFile()
{

}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::clearAllItems()
{
	manager->clearAllItems();
}

void MainScreen::close()
{
	exit(0);
}

void MainScreen::clearLastItem()
{
	manager->clearLastItem();
}