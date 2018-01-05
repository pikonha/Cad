#pragma once
#ifndef INCLUDED_MAINCMD_H
#define INCLUDED_MAINCMD_H

#include "FormType.h"

class Point;
class Geometry;
class Data;

class MainCmd
{
protected:
	FormType form;

   Data& data;

	bool drawing;
	bool auxDraw;
	bool secondClick;
   
   /*void setMessageToScreen(Instruction in);*/
   
public:
   virtual ~MainCmd() {}
	MainCmd(Data& d) : data(d) { drawing = auxDraw = secondClick= false; /*setMessageToScreen(MOUSECLICK);*/ }

	virtual void setP1(const Point& p) = 0;
	virtual void setP2(const Point& p) = 0;
	virtual void setP3(const Point& p) {}
  
   /////AUXS
   void setDrawing(bool drwOk);
   void setAuxDraw(bool status);
   bool getSecondClick() const { return secondClick; }
   
	FormType getForm() { return form; }

	virtual Geometry* getNewGeometry() = 0;

   /////MOUSE EVENTS
   virtual void mousePressEvent(Point& p) = 0;
   virtual void mouseReleaseEvent(Point& p) = 0;
   virtual void mouseMoveEvent(Point& p) = 0;
};

#endif