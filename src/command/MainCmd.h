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

   QGraphicsItem* geoModel;

	AuxLineModel* auxLine;

   void setMessageToScreen(Instruction in);
public:
   virtual ~MainCmd() {}
	MainCmd(MainScreen& v) : auxLine(nullptr), geoModel(nullptr), screen(v) {drawing = auxDraw = secondClick= false; }	

	virtual void execute(Data& d, MainScreen& s) = 0;

	virtual void setP1(const Point& p) = 0;
	virtual void setP2(const Point& p) = 0;
	virtual void setP3(const Point& p) {}

	void setDrawing(bool drwOk) { drawing = drwOk; screen.getView()->setMouseTracking(drwOk); }
   bool getSecondClick() { return secondClick; }
	void setAuxDraw(bool status) { auxDraw = status; screen.getView()->setMouseTracking(status); }

	virtual void createAuxLine(const Point& p, const Point& o);
	virtual AuxLineModel* getAuxLine();

	FormType getForm() { return form; }

	virtual Geometry* getNewGeometry() = 0;

	void draw();

	virtual QGraphicsItem* getQtGraphicGeo() = 0; 

public:
   virtual void mousePressEvent(Point& p) = 0;
   virtual void mouseReleaseEvent(Point& p, Data& d) = 0;
   virtual void mouseMoveEvent(Point& p) = 0;
};

#endif