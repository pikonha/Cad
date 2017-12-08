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
	view = screen->getView();
	screen = new MainScreen(manager);
	manager = new Manager(data, screen);
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
	screen->start();

	return app.exec();
}
