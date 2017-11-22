#pragma once
#include <QGraphicsItem>
#include <QMouseEvent>

class Line : public QGraphicsItem
{
private:
	QPoint x;
	QPoint y;

	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	QPainterPath getPath();
public:
	Line() {}
	Line(const QPoint& x, const QPoint& y, QGraphicsItem* parent = 0);
	~Line() {}
};
