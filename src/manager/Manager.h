#pragma once
#ifndef INCLUDED_MANAGER_H
#define INCLUDED_MANAGER_H

namespace Manager
{
	void mousePressEvent();
	void mouseReleaseEvent();
	void mouseMoveEvent();

	void newFile();
	void openFile();
	void clearFile();
	void closeFile();

	void line();
	void bezier();
	void arch();

	void clearLastItem();

	void drawAuxLine();

};

#endif