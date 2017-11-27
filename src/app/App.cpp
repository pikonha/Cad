#include "App.h"
#include "CmdNew.h"
#include "CmdIdle.h"
#include "CmdSave.h"
#include "CmdZoom.h"
#include "CmdLoad.h"
#include "CmdClear.h"
#include "CmdClose.h"
#include "CmdDrawLine.h"
#include "CmdDrawArch.h"
#include "CmdMouseMove.h"
#include "CmdDrawBezier.h"
#include "CmdMouseClick.h"
#include "CmdMousePress.h"
#include "CmdSetStatusBar.h"
#include "Line.h"
#include "Bezier.h"
#include "Arch.h"

App::~App() {
	delete cmd;
	delete screen;
	delete view;
}

/////SETUP
App::App()
{
	cmd = new CmdIdle();
	screen = new MainScreen();
	view = screen->getView();
	form = LINE;
	auxDraw = drawingArch = false;
	firstClick = true;
	currentItem = new Line();
}

App* App::app = nullptr;
App* App::getInstance()
{
	if (!app)
		app = new App();

	return app;
}

void App::start(int argc, char** argv)
{
	QApplication app(argc, argv);
	screen->start(&app);
}

/////CMD
void App::newCmd(Cmd* command)
{
	setCmd(command);
	executeCmd();
	setCmdIdle();
}

/////FORM
std::string App::getForm()
{
	switch (form)
	{
	case LINE: return "Line";
	case BEZIER: return "Bezier";
	case ARCH: return "Arc";
	}
}

/////ITEMS
void App::clearItens()
{
	itens.clear();
}

void App::clearLastItem()
{
	if (itens.empty())
		return;

	view->getScene()->removeItem(itens.back());
	itens.pop_back();
	view->getScene()->update();
}

/////DRAW


/////FILE
void saveFile(){}
void openFile(){}