#pragma once
#ifndef INCLUDED_MAINCMD_H
#define INCLUDED_MAINCMD_H
#include "MainScreen.h"
#include "FormType.h"
#include "Cmd.h"
#include "AuxLineModel.h"

class MainCmd : public Cmd
{
protected:
	FormType form;
	MainScreen& screen;

	bool drawing;
	bool auxDraw;
	bool secondClick;

	AuxLineModel* auxLine;
public:
   virtual ~MainCmd() {}
	MainCmd(MainScreen& v) : auxLine(nullptr), screen(v) {drawing = auxDraw = secondClick= false; }	

	virtual void execute(Data& d, MainScreen& s) = 0;

	virtual void setP1(Point* p) = 0;
	virtual void setP2(Point* p) = 0;
	virtual void setP3(Point* p) {}

	void setDrawing(bool d, MainView* view) { drawing = d; view->setMouseTracking(d); }
   bool getSecondClick() { return secondClick; }
	void setAuxDraw(bool status, MainView* view) { auxDraw = status; view->setMouseTracking(status); }

	virtual void createAuxLine(Point* p, Point* o);
	virtual AuxLineModel* getAuxLine();

	FormType getForm() { return form; }

	virtual Item* getItem() = 0;

	void draw();

	virtual QGraphicsItem* getModel() = 0;

public:
   virtual void mousePressEvent(Point& p) = 0;
   virtual void mouseReleaseEvent(Point& p, Data& d) = 0;
   virtual void mouseMoveEvent(Point& p) = 0;
};

#endif