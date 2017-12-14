#pragma once
#ifndef INCLUDED_MAINCMD_H
#define INCLUDED_MAINCMD_H
#include "MainScreen.h"
#include "Form.h"
#include "Data.h"
#include "Cmd.h"
#include "AuxLineModel.h"

class MainCmd : public Cmd
{
protected:
	Form form;
	MainScreen* screen;

	bool drawing;
	bool auxDraw;

	AuxLineModel* auxLine;
public:
	MainCmd(MainScreen* v) : auxLine(nullptr) { screen = v; drawing = auxDraw = false; }
	virtual ~MainCmd() {}

	virtual void execute(Data& d, MainScreen& s) = 0;

	virtual void setP1(Point* p) = 0;
	virtual void setP2(Point* p) = 0;
	virtual void setP3(Point* p) {}

	bool getDrawing() { return drawing; }
	void setDrawing(bool d, MainView* view) { drawing = d; view->setMouseTracking(d); }
	
	void setAuxLine(AuxLineModel* model) { auxLine = model; }

	bool getAuxDraw() { return auxDraw; }
	void setAuxDraw(bool status, MainView* view) { auxDraw = status; view->setMouseTracking(status); }

	virtual void createAuxLine(Point* p, Point* o);
	virtual AuxLineModel* getAuxLine();

	Form getForm() { return form; }

	virtual Item* getItem() = 0;

	void draw();

	virtual QGraphicsItem* getModel() = 0;
};

#endif