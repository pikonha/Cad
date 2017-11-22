#include "Arch.h"
#include <QPainter>
#include <QLine>
#include <qmath.h>

#define _USE_MATH_DEFINES

Arch::Arch(const QPoint& x, const QPoint& y, const QPoint& z)
{
	raio = new QLine(x, y);
	center = x;
	controle = z;

	sumCos = sumSin = false;
}

double Arch::pointDistance(QPoint x, QPoint y)
{
	return std::sqrt(pow(y.x() - x.x(),2) + pow(y.y() - x.y(), 2));
}


double Arch::getAngleArcSen(double cateto, double hipotenusa) {
	return asin(cateto / hipotenusa) * 180 / M_PI;
}

QPoint Arch::findArchPoint(double auxAngle) {
	double raioLenght = pointDistance(raio->p1(), raio->p2());

	double ang = auxAngle * M_PI / 180;

	double auxX = cos(ang) * raioLenght;
	double auxY = sin(ang) * raioLenght;

	double a = center.x() + auxX;
	double b = center.y() - auxY;

	return QPoint(a, b);
}

QPainterPath Arch::getPath()
{
	double raioLenght = pointDistance(raio->p1(), raio->p2());
	double incrementAngle;
	QPainterPath path(raio->p2());

	int quadrantControle = getQuadrant(controle);
	int quadrantB = getQuadrant(raio->p2());

	double distanceEB;
	double distanceDC;
	double distanceAC;
	double angleG;
	double angleB;
	double auxY;
	double auxX;

		switch (quadrantB)
		{
		case 1:
			sumCos = true;
			sumSin = false;

			switch (quadrantControle) {
			case 1:

				if (raio->p2().x() < controle.x()) {
					distanceEB = pointDistance(QPoint(center.x(), raio->p2().y()), raio->p2());
					angleG = getAngleArcSen(distanceEB, raioLenght);

					distanceDC = pointDistance(QPoint(controle.x(),center.y()), controle);
					distanceAC = pointDistance(center, controle);
					angleB = getAngleArcSen(distanceDC, distanceAC);
					
					angle = 270 + angleB + angleG;
					incrementAngle = 90 - angleG;

					while (incrementAngle <= 360 + angleB) {

						path.lineTo(findArchPoint(incrementAngle));

						incrementAngle += angle / 200;
					}
				}
				else
				{
					distanceEB = pointDistance(QPoint(raio->p2().x(),center.y()), raio->p2());
					angleG = getAngleArcSen(distanceEB, raioLenght);

					distanceDC = pointDistance(QPoint(center.x(), controle.y()), controle);
					distanceAC = pointDistance(center, controle);
					angleB = getAngleArcSen(distanceDC, distanceAC);

					angle = 90 - angleB - angleG;
					incrementAngle = angleG;

					while (incrementAngle <= angle + angleG)
					{
						path.lineTo(findArchPoint(incrementAngle));

						incrementAngle += angle / 50;
					}
				}

				break;

			case 2:

				distanceEB = pointDistance(QPoint(raio->p2().x(), center.y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(controle.x(), center.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 180 - angleB - angleG;
				incrementAngle = angleG;

				while (incrementAngle <= angle + angleG)
				{
					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle / 100;
				}
				break;

			case 3:
				distanceEB = pointDistance(QPoint(raio->p2().x(), center.y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(center.x(), controle.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 270 - angleB - angleG;
				incrementAngle = angleG;

				while (incrementAngle <= angle + angleG) {

					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle / 150;
				}
				break;

			case 4:

				distanceEB = pointDistance(QPoint(raio->p2().x(), center.y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(controle.x(), center.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 360 - angleB - angleG;
				incrementAngle = angleG;

				while (incrementAngle <= angle + angleG)
				{
					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle / 200;
				}
				break;
			}

			break;
		case 2:
			switch (quadrantControle) {
			case 1:

				distanceEB = pointDistance(QPoint(center.x(), raio->p2().y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(center.x(), controle.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 180 + (90 - angleG) + (90 - angleB);
				incrementAngle = 90 + angleG;

				while (incrementAngle <= 360 + (90 - angleB)) {

					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle / 150;
				}

			break;

			case 2:

				if (raio->p2().x() < controle.x()) {
					distanceEB = pointDistance(QPoint(raio->p2().x(), center.y()), raio->p2());
					angleG = getAngleArcSen(distanceEB, raioLenght);

					distanceDC = pointDistance(QPoint(center.x(), controle.y()), controle);
					distanceAC = pointDistance(center, controle);
					angleB = getAngleArcSen(distanceDC, distanceAC);

					angle = 270 + angleB + angleG;
					incrementAngle = 90 + ( 90 - angleG);

					while (incrementAngle <= 450 + (90 - angleG)) {

						path.lineTo(findArchPoint(incrementAngle));

						incrementAngle += angle / 200;
					}
				}
				else 
				{
					distanceEB = pointDistance(QPoint(center.x(), raio->p2().y()), raio->p2());
					angleG = getAngleArcSen(distanceEB, raioLenght);

					distanceDC = pointDistance(QPoint(controle.x(), center.y()), controle);
					distanceAC = pointDistance(center, controle);
					angleB = getAngleArcSen(distanceDC, distanceAC);

					angle = 90 - angleB - angleG;
					incrementAngle = 90 + angleG;

					while (incrementAngle <= 180 - angleB) {

						path.lineTo(findArchPoint(incrementAngle));

						incrementAngle += angle / 50;
					}
				}
				break;

			case 3:
				distanceEB = pointDistance(QPoint(center.x(), raio->p2().y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(center.x(), controle.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 180 - angleB - angleG;
				incrementAngle = 90 + angleG;

				while (incrementAngle <= 270 - angleB) {

					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle / 100;
				}
				break;
			case 4: 
				distanceEB = pointDistance(QPoint(center.x(), raio->p2().y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(controle.x(), center.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 270 - angleB - angleG;
				incrementAngle = 90 + angleG;

				while (incrementAngle <= 360 - angleB) {

					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle / 150;
				}
				break;
			}

			break;
		case 3:
			switch (quadrantControle) {
			case 1:
				distanceEB = pointDistance(QPoint(raio->p2().x(), center.y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(center.x(), controle.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 270 - angleB - angleG;
				incrementAngle = 180 + angleG;

				while (incrementAngle <= 360 + ( 90 - angleB)) {

					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle / 150;
				}
				break;
			case 2:
				distanceEB = pointDistance(QPoint(raio->p2().x(), center.y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(controle.x(), center.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 360 - angleB - angleG;
				incrementAngle = 180 + angleG;

				while (incrementAngle <= 450 + (90 - angleB)) {

					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle / 100;
				}
				break;
			case 3:

				if (raio->p2().x() < controle.x())
				{
					distanceEB = pointDistance(QPoint(raio->p2().x(), center.y()), raio->p2());
					angleG = getAngleArcSen(distanceEB, raioLenght);

					distanceDC = pointDistance(QPoint(center.x(), controle.y()), controle);
					distanceAC = pointDistance(center, controle);
					angleB = getAngleArcSen(distanceDC, distanceAC);

					angle = 90 - angleB - angleG;
					incrementAngle = 180 + angleG;

					while (incrementAngle <= 270 - angleB) {

						path.lineTo(findArchPoint(incrementAngle));

						incrementAngle += angle / 150;
					}
				}
				else
				{
					distanceEB = pointDistance(QPoint(center.x(), raio->p2().y()), raio->p2());
					angleG = getAngleArcSen(distanceEB, raioLenght);

					distanceDC = pointDistance(QPoint(controle.x(), center.y()), controle);
					distanceAC = pointDistance(center, controle);
					angleB = getAngleArcSen(distanceDC, distanceAC);

					angle = 270 + angleB + angleG;
					incrementAngle = 270 - angleG;

					while (incrementAngle <= 540 + angleB) {

						path.lineTo(findArchPoint(incrementAngle));

						incrementAngle += angle / 200;
					}
				}

				break;
			case 4:
				distanceEB = pointDistance(QPoint(raio->p2().x(), center.y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(controle.x(), center.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 180 - angleB - angleG;
				incrementAngle = 180 + angleG;

				while (incrementAngle <= 360 - angleB) {

					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle / 50;
				}
				break;
			}
			break;
		case 4:
			switch (quadrantControle) {
			case 1:
				distanceEB = pointDistance(QPoint(center.x(), raio->p2().y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(center.x(), controle.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 180 - angleB - angleG;
				incrementAngle = 270 + angleG;

				while (incrementAngle <= 360 + (90 - angleB)) {

					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle /100;
				}
				break;
			case 2:
				distanceEB = pointDistance(QPoint(center.x(), raio->p2().y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(controle.x(), center.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 270 - angleB - angleG;
				incrementAngle = 270 + angleG;

				while (incrementAngle <= 450 + (90 - angleB)) {

					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle / 150;
				}
				break;
			case 3:
				distanceEB = pointDistance(QPoint(center.x(), raio->p2().y()), raio->p2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(QPoint(center.x(), controle.y()), controle);
				distanceAC = pointDistance(center, controle);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 180 + angleB + angleG;
				incrementAngle = 270 + angleG;

				while (incrementAngle <= 540 + (90 - angleB)) {

					path.lineTo(findArchPoint(incrementAngle));

					incrementAngle += angle / 200;
				}
				break;
			case 4:
				if (raio->p2().x() < controle.x())
				{
					distanceEB = pointDistance(QPoint(center.x(), raio->p2().y()), raio->p2());
					angleG = getAngleArcSen(distanceEB, raioLenght);

					distanceDC = pointDistance(QPoint(controle.x(),center.y()), controle);
					distanceAC = pointDistance(center, controle);
					angleB = getAngleArcSen(distanceDC, distanceAC);

					angle = 90 - angleB - angleG;
					incrementAngle = 270 + angleG;

					while (incrementAngle <= 360 - angleB) {

						path.lineTo(findArchPoint(incrementAngle));

						incrementAngle += angle / 50;
					}
				}
				else
				{
					distanceEB = pointDistance(QPoint(raio->p2().x(), center.y()), raio->p2());
					angleG = getAngleArcSen(distanceEB, raioLenght);

					distanceDC = pointDistance(QPoint(center.x(), controle.y()), controle);
					distanceAC = pointDistance(center, controle);
					angleB = getAngleArcSen(distanceDC, distanceAC);

					angle = 270 + angleB + angleG;
					incrementAngle = 360 - angleG;

					while (incrementAngle <= 630 + angleB) {

						path.lineTo(findArchPoint(incrementAngle));

						incrementAngle += angle / 200;
					}
				}
				
			}
			break;
		}
	

	return path;
}




void Arch::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawPath(getPath());
}

int Arch::getQuadrant(QPoint p) 
{
	if (p.x() >= center.x())
	{
		if (p.y() <= center.y())
			return 1;

		else
			return 4;
	}
	else if (p.x() < center.x())
	{
		if (p.y() <= center.y())
			return 2;

		else
			return 3;
	}
}
