#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#include "MainScreen.h"
#include "Cmd.h"
#include <vector>

enum Form
{
	LINE, BEZIER, ARCH
};


class App
{
private:
	static App* app;

	Cmd* cmd;
	MainScreen* screen;	
	MainView* view;
	Form form;

	QPoint x;
	QPoint y;
	QPoint z;

	QGraphicsItem* currentItem;
	QGraphicsItem* auxLine;

	bool auxDraw;
	bool drawingArch;
	bool firstClick;

	std::vector<QGraphicsItem*> itens;

	App();
public:
	~App();

	/////SETUP
	static App* getInstance();
	void start(int argc, char** argv);

	/////CMD
	Cmd* getCmd() { return cmd; }
	void setCmd(Cmd* command) { cmd = command; }
	void executeCmd() { cmd->execute();  }
	void setCmdIdle() { cmd = new CmdIdle(); }

	void newCmd(Cmd* command);

	/////FORM
	std::string getForm();
	void setForm(Form shape) { form = shape; }

	/////ITENS
	void addItem(QGraphicsItem* item) { itens.push_back(item); }
	void clearItens();
	void clearLastItem();

	QGraphicsItem* getCurrentItem() { return currentItem; }
	void setCurrentItem(QGraphicsItem* item) { currentItem = item; }
	void deleteCurrentItem() { delete currentItem; }

	/////POINTS
	QPoint getX() { return x; }
	QPoint getY() { return y; }
	QPoint getZ() { return z; }

	void setX(QPoint p) { x = p; }
	void setY(QPoint p) { y = p; }
	void setZ(QPoint p) { z = p; }

	void clearPoints() { x = y = z = QPoint(0,0); }

	/////DRAW

	bool getAuxDraw() { return auxDraw; }
	bool getDrawingArch() { return drawingArch; }
	bool getFirstClick() { return firstClick; }

	void setAuxDraw(bool status) { auxDraw = status; }
	void setDrawingArch(bool status) { drawingArch = status; }
	void setFirstClick(bool status) { firstClick = status; }

	/////FILE
	void saveFile();
	void openFile();
};

#endif 