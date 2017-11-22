#include <MainScreen.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	MainScreen::getInstance()->start(&app);
}
