#include "App.h"
#include "Manager.h"
#include <qapplication.h>
#include <QtCore>

App::~App() {
	delete cmd;
	delete screen;
	delete view;
	delete data;
}

/////SETUP
App::App()
{
	cmd = new CmdIdle();	
	view = screen->getView();
	data = new Data();	
	manager = new Manager(this);
	screen = new MainScreen(manager);
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

/////CMD
void App::runCmd(Cmd* command)
{
	setCmd(command);
	executeCmd();
	deleteCmd();
	setCmdIdle();
}

/////FILE
void saveFile(){}
void openFile(){}