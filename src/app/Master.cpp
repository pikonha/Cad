#include "App.h"
#include <crtdbg.h>

int main(int argc, char* argv[])
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtMemState s1;

	App::getInstance().start(argc, argv);

	_CrtMemCheckpoint(&s1);
	_CrtMemDumpStatistics(&s1);
}
