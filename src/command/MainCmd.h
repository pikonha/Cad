#pragma once
#ifndef INCLUDED_MAINCMD_H
#define INCLUDED_MAINCMD_H
#include "MainView.h"
#include "Form.h"
#include "Data.h"
#include "AuxLineModel.h"

class MainCmd
{
protected:
	Data* data;
	MainView* view;
	Form form;

	bool drawing;
	bool auxDraw;

	AuxLineModel* auxLine;
public:
	MainCmd(Data* d, MainView* s, Form f) { data = d; view = s; form = f; drawing = auxDraw = false; }
	~MainCmd() {}

	virtual void execute() = 0;

	virtual void setP1(Point p) = 0;
	virtual void setP2(Point p) = 0;
	virtual void setP3(Point p) {}

	bool getDrawing() { return drawing; }
	void setDrawing(bool d) { drawing = d; view->setMouseTracking(d); }

	bool getAuxDraw() { return auxDraw; }
	void setAuxDraw(bool status) { auxDraw = status; }

	virtual void createAuxLine(Point p, Point o);
	virtual AuxLineModel* getAuxLine();

	Form getForm() { return form; }

	virtual Item* getItem() = 0;

	void draw();

	virtual QGraphicsItem* getModel() = 0;
};

#endif