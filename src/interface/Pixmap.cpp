#include "Pixmap.h"

Pixmap::Pixmap(QSize size) : QPixmap(size)
{
   fill();
   painter.begin(this);

}

void Pixmap::draw(const QPainterPath path)
{
   painter.drawPath(path);
}

void Pixmap::clear()
{
   fill();
}
