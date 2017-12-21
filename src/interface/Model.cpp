#include "Model.h"
#include <QPainter>

QRectF Model::boundingRect() const
{
	return QRectF(0, 0, 1920, 1080);
}

void Model::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
   painter->drawPath(getPath());
}

QPoint Model::pointConversor(const Point& p)
{
	return QPoint(p.x, p.y);
}

QPainterPath Model::getPath()
{
   QPainterPath path;
   auto allPt= geo.getPoints();

   path.moveTo(pointConversor(allPt.front()));
   for (auto& p :allPt)
      path.lineTo(pointConversor(p));

   return path;
}