#pragma once
#ifndef INCLUDED_ARCHMODEL_H
#define INCLUDED_ARCHMODEL_H
#include <QGraphicsItem>
#include "Point.h"

class Arch;

class ArchModel : public QGraphicsItem
{
private:
	Arch* arch;

public:
	ArchModel() {}
	ArchModel(QPoint a, QPoint b, QPoint c);
	~ArchModel() {}

protected:
	QRectF boundingRect() const override { return QRect(0, 0, 1920, 1080); }
	QPainterPath getPath();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	QPoint* pointConversor(Point p);
};

#endif