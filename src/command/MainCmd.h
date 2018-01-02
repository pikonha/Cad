#pragma once
#ifndef INCLUDED_MAINCMD_H
#define INCLUDED_MAINCMD_H

#include "FormType.h"
#include "View.h"
class Data;

class MainCmd
{
protected:
	FormType form;

   View& view;
   File& file;

	bool drawing;
	bool auxDraw;
	bool secondClick;
   
   /*void setMessageToScreen(Instruction in);*/
   
public:
   virtual ~MainCmd() {}
	MainCmd(View& v, File& f) : view(v), file(f) { drawing = auxDraw = secondClick= false; /*setMessageToScreen(MOUSECLICK);*/ }

	virtual void setP1(const Point& p) = 0;
	virtual void setP2(const Point& p) = 0;
	virtual void setP3(const Point& p) {}
  
   void setDrawing(bool drwOk);
   void setAuxDraw(bool status);
   bool getSecondClick() { return secondClick; }
   
	FormType getForm() { return form; }

	virtual Geometry* getNewGeometry() = 0;

   void save(Geometry* geo);
	void draw(Geometry* geo);

   /////MOUSE EVENTS
   virtual void mousePressEvent(Point& p) = 0;
   virtual void mouseReleaseEvent(Point& p, Data& d) = 0;
   virtual void mouseMoveEvent(Point& p) = 0;
};

#endif