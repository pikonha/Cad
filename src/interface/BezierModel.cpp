#include "BezierModel.h"

QPainterPath BezierModel::getPath()
{
	QPainterPath path(*pointConversor(item->getPoints().front()));

	for (int i = 1; i < item->getPoints().size() ; i++) 
		path.lineTo(*pointConversor(item->getPoints().at(i)));

	return path;
}