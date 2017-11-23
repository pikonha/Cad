#include "App.h"

App* App::getInstance()
{
	if (!app)
		app = new App();

	return app;
}

void App::start()
{

}