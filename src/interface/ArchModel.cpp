#include "ArchModel.h"
#include <QPainter>
#include "Point.h"
#include "Arch.h"

QPainterPath ArchModel::getPath()
{
	QPainterPath path(*pointConversor(item->getPoints().front()));

	for (int i = 1; i < item->getPoints().size(); i++) 
		path.lineTo(*pointConversor(item->getPoints().at(i)));
	
	return path;
}


void ArchModel::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawPath(getPath());
}


QRectF ArchModel::boundingRect() const
{
	return QRect(0, 0, 1920, 1080);
}

QPoint* ArchModel::pointConversor(Point p)
{
	return new QPoint(p.getX(), p.getY());
}
