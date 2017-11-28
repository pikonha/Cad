#include "MainScreen.h"
#include "QStatusBar"
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QIcon>
#include <QShortcut>
#include <QStatusBar>

MainScreen::MainScreen(Manager* m, QMainWindow* parent) : QMainWindow(parent)
{
	setFixedSize(1920, 1020);
	showMaximized();

	view = new MainView(m);
	navbar = menuBar();	
	status = new QStatusBar(this);
	setStatusBar(status);

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

	connect(line, &QAction::triggered, m, &Manager::setLine);
	connect(bezier, &QAction::triggered, m, &Manager::setBezier);
	connect(arc, &QAction::triggered, m, &Manager::setArch);
	

	connect(open, &QAction::triggered, m, &Manager::openFile);
	connect(save, &QAction::triggered, m, &Manager::saveFile);
	connect(clear, &QAction::triggered, m, &Manager::clearAllItems);
	connect(close, &QAction::triggered, this, &MainScreen::close);

	QShortcut* undone = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
	connect(undone, &QShortcut::activated, m, &Manager::clearLastItem);
}


MainScreen::~MainScreen()
{
	delete view;
}


int MainScreen::start()
{
	show();
}

void MainScreen::setZoom(double scale)
{
	
}

void MainScreen::setTxtStatusBar()
{
	//status->messageChanged(view->getCurrentShape);
}
