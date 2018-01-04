#include "App.h"
#include "Manager.h"
#include <QtWidgets/QApplication>
#include <QtCore>
#include "Data.h"
#include "MainScreen.h"

App* App::app= nullptr;
App::~App() 
{
   if (screen)
		delete screen;

   if (data)
	   delete data;

   if (manager)
	   delete manager;
}

/////SETUP
App::App()
{		
	data= nullptr;
	screen= nullptr;
	manager= nullptr;
}


App& App::getInstance()
{
	if (!app)
		app= new App;

	return *app;
}

int App::start(int argc, char** argv)
{
	QApplication app(argc, argv);		

	screen= new MainScreen();

	data= new Data;

	manager= new Manager(*data,*screen);
   screen->setManager(*manager);

	return app.exec();
}
