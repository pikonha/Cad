#include "App.h"
#include "Manager.h"
#include <qapplication.h>
#include <QtCore>
#include "Data.h"
#include "MainScreen.h"

App::~App() {
	delete screen;
	delete view;
	delete data;
	delete manager;
}

/////SETUP
App::App()
{		
	data = new Data();		
}

App* App::app = nullptr;
App* App::getInstance()
{
	if (!app)
		app = new App();

	return app;
}

int App::start(int argc, char** argv)
{
	QApplication app(argc, argv);
	screen = new MainScreen(manager);
	view = screen->getView();
	manager = new Manager(data, screen);
	view->setManager(manager);

	screen->start();

	return app.exec();
}
