#include "Model.h"
#include <QPainter>

bool Model::operator==(Model* m)
{
	if (*geo == m->getGeo())
		return true;

	return false;
}

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
	std::vector<Point> points= geo->getPoints();
	
   
   QPainterPath path(pointConversor(points.front()));

   for (int i = 1; i < points.size(); i++)
      path.lineTo(pointConversor(points.at(i)));

   return path;
}