#include "MainScreen.h"
#include "QStatusBar"
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QIcon>
#include <QShortcut>
#include <QStatusBar>

MainScreen::MainScreen(QMainWindow* parent) : QMainWindow(parent)
{
	//setMinimumSize(800, 600);
	setFixedSize(1920, 1020);
	showMaximized();

	view = new MainView();
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

	QIcon* iconSave = new QIcon("C:/Users/lucas.picollo/Documents/QT/icons/save.png");
	QIcon* iconClear = new QIcon("C:/Users/lucas.picollo/Documents/QT/icons/clean.png");
	QIcon* iconClose = new QIcon("C:/Users/lucas.picollo/Documents/QT/icons/close.png");
	QIcon* iconOpen = new QIcon("C:/Users/lucas.picollo/Documents/QT/icons/open.png");

	open->setIcon(*iconOpen);
	save->setIcon(*iconSave);
	clear->setIcon(*iconClear);
	close->setIcon(*iconClose);

	navbar->addMenu(file);
	navbar->addAction(line);
	navbar->addAction(bezier);
	navbar->addAction(arc);
	
	setCentralWidget(view);

	connect(line, &QAction::triggered, view, &MainView::setLine);	
	connect(bezier, &QAction::triggered, view, &MainView::setBezier);	
	connect(arc, &QAction::triggered, view, &MainView::setArch);	

	connect(open, &QAction::triggered, view, &MainView::openFile);
	connect(save, &QAction::triggered, view, &MainView::saveFile);
	connect(clear, &QAction::triggered, view->getScene(), &QGraphicsScene::clear);
	connect(clear, &QAction::triggered, view, &MainView::clearItens);
	connect(close, &QAction::triggered, this, &MainScreen::close);

	QShortcut* undone = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
	connect(undone, &QShortcut::activated, view, &MainView::clearLastItem);
}


MainScreen::~MainScreen()
{
	delete view;
}


int MainScreen::start(QApplication* app)
{
	show();

	return app->exec();
}

void MainScreen::setZoom(double scale)
{
	
}

void MainScreen::setTxtStatusBar()
{
	//status->messageChanged(view->getCurrentShape);
}
