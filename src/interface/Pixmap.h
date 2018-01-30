#pragma once
#ifndef INCLUDED_PIXMAP_H
#define INCLUDED_PIXMAP_H

#include <QPainter>

class Pixmap : public QPixmap
{
   QPainter painter;
   
   QPoint start;
   QPoint finish;

public:
   Pixmap(QSize size);
   ~Pixmap() {}

   void draw(QPainterPath path);

   void clear();
};

#endif