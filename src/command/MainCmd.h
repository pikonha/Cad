#pragma once
#ifndef INCLUDED_MAINCMD_H
#define INCLUDED_MAINCMD_H
#include "Data.h"
#include "MainView.h"
#include "Item.h"
#include "Form.h"
#include "LineModel.h"

class MainCmd
{
protected:
	Data* data;
	MainView* view;
	Form form;

	bool drawing;
	bool drawingAux;

	QGraphicsItem* auxLine;
public:
	MainCmd(Data* d, MainView* s, Form f) { data = d; view = s; form = f; drawing = drawingAux = false; }
	~MainCmd() {}

	virtual void execute() = 0;

	virtual void setP1(Point p) = 0;
	virtual void setP2(Point p) = 0;
	virtual void setP3(Point p) {}
	
	virtual void draw() = 0;

	bool getDrawing() { return drawing; }
	void setDrawing(bool d) { drawing = d; view->setMouseTracking(d); }

	bool getDrawingAux() { return drawingAux; }
	void setDrawingAux(bool b) { drawingAux = b; }

	virtual void createAuxLine(LineModel* i) { auxLine = i; }
	QGraphicsItem* getAuxLine() { retrun auxLine; }

	void save(QGraphicsItem* model) { view->save(model); }

	Form getForm() { return form; }

	virtual Item* getItem() = 0;
};

#endif