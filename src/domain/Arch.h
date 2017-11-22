#pragma once
#include <QGraphicsItem>

class Arch :
	public QGraphicsItem
{
private:
	QLine* raio;
	QPoint controle;
	QPoint center;
	double angle;

	bool sumSin;
	bool sumCos;
public:
	Arch() {}
	Arch(const QPoint& x, const QPoint& y, const QPoint& z);
	~Arch() {}

	double pointDistance(QPoint x, QPoint y);

	int getQuadrant(QPoint p);
	double getAngleArcSen(double cateto, double hipotenusa);

	QPoint findArchPoint(double auxAngle);
protected:
	QRectF boundingRect() const override { return QRect(0, 0, 1920, 1080); }
	QPainterPath getPath();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
};

