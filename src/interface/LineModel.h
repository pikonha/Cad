#pragma once
#ifndef INCLUDED_LINEMODEL_H
#define INCLUDED_LINEMODEL_H
#include <QGraphicsItem>

class Line;

class LineModel : public QGraphicsItem
{
private:
	Line* line;	

	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	QPainterPath getPath();
public:
	LineModel() {}
	LineModel(QPoint x, QPoint y, QGraphicsItem* parent = 0);
	~LineModel();
};

#endif