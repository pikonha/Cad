#pragma once
#ifndef INCLUDED_MAINCMD_H
#define INCLUDED_MAINCMD_H

#include "FormType.h"
#include "Line.h"
#include "Instruction.h"

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

   static void setMessageToScreen(Instruction in);
   
public:
   virtual ~MainCmd() {}
   MainCmd(Data& d) : data(d) { drawing = auxDraw = secondClick= false; }
  
   /////AUXS
   void setDrawing(bool drwOk);
   void setAuxDraw(bool status);
   bool getSecondClick() const { return secondClick; }
   
	FormType getForm() const { return form; }

   /////MOUSE EVENTS
   virtual void mousePressEvent(Point& p) = 0;
   virtual void mouseReleaseEvent(Point& p) = 0;
   virtual void mouseMoveEvent(Point& p) = 0;
};

#endif