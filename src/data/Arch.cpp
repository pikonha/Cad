#include "Arch.h"
#include "Line.h"
#define _USE_MATH_DEFINES
#include <math.h>


Arch::Arch(Point* a, Point* b, Point* c) : Item(a,b)
{
	raio = new Line(a, b);
	center = a;
	control = c;
}

double Arch::pointDistance(Point* x, Point* y)
{
	return std::sqrt(pow(y->getX() - x->getX(), 2) + pow(y->getY() - x->getY(), 2));
}


double Arch::getAngleArcSen(double cateto, double hipotenusa) {
	return asin(cateto / hipotenusa) * 180 / M_PI;
}

Point* Arch::findArchPoint(double auxAngle) {
	double raioLenght = pointDistance(raio->getP1(), raio->getP2());

	double ang = auxAngle * M_PI / 180;

	double auxX = cos(ang) * raioLenght;
	double auxY = sin(ang) * raioLenght;

	double a = center->getX() + auxX;
	double b = center->getY() - auxY;

	return new Point(a, b);
}

std::vector<Point*> Arch::getPoints()
{
	double raioLenght = pointDistance(raio->getP1(), raio->getP2());
	double incrementAngle;

	std::vector<Point*> points;
	points.push_back(raio->getP2());

	int quadrantControle = getQuadrant(control);
	int quadrantB = getQuadrant(raio->getP2());

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
		switch (quadrantControle) {
		case 1:

			if (raio->getP2()->getX() < control->getX()) {
				distanceEB = pointDistance(new Point(center->getX(), raio->getP2()->getY()), raio->getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(new Point(control->getX(), center->getY()), control);
				distanceAC = pointDistance(center, control);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 270 + angleB + angleG;
				incrementAngle = 90 - angleG;

				while (incrementAngle <= 360 + angleB) {

					points.push_back(findArchPoint(incrementAngle));

					incrementAngle += angle / 200;
				}
			}
			else
			{
				distanceEB = pointDistance(new Point(raio->getP2()->getX(), center->getY()), raio->getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(new Point(center->getX(), control->getY()), control);
				distanceAC = pointDistance(center, control);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 90 - angleB - angleG;
				incrementAngle = angleG;

				while (incrementAngle <= angle + angleG)
				{
					points.push_back(findArchPoint(incrementAngle));

					incrementAngle += angle / 50;
				}
			}

			break;

		case 2:

			distanceEB = pointDistance(new Point(raio->getP2()->getX(), center->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(control->getX(), center->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 - angleB - angleG;
			incrementAngle = angleG;

			while (incrementAngle <= angle + angleG)
			{
				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 100;
			}
			break;

		case 3:
			distanceEB = pointDistance(new Point(raio->getP2()->getX(), center->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(center->getX(), control->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 270 - angleB - angleG;
			incrementAngle = angleG;

			while (incrementAngle <= angle + angleG)
			{
				points.push_back(findArchPoint(incrementAngle));
				incrementAngle += angle / 150;
			}
			break;

		case 4:

			distanceEB = pointDistance(new Point(raio->getP2()->getX(), center->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(control->getX(), center->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 360 - angleB - angleG;
			incrementAngle = angleG;

			while (incrementAngle <= angle + angleG)
			{
				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 200;
			}
			break;
		}

		break;
	case 2:
		switch (quadrantControle) {
		case 1:

			distanceEB = pointDistance(new Point(center->getX(), raio->getP2()->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(center->getX(), control->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 + (90 - angleG) + (90 - angleB);
			incrementAngle = 90 + angleG;

			while (incrementAngle <= 360 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 150;
			}

			break;

		case 2:

			if (raio->getP2()->getX() < control->getX()) {
				distanceEB = pointDistance(new Point(raio->getP2()->getX(), center->getY()), raio->getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(new Point(center->getX(), control->getY()), control);
				distanceAC = pointDistance(center, control);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 270 + angleB + angleG;
				incrementAngle = 90 + (90 - angleG);

				while (incrementAngle <= 450 + (90 - angleG)) {

					points.push_back(findArchPoint(incrementAngle));

					incrementAngle += angle / 200;
				}
			}
			else
			{
				distanceEB = pointDistance(new Point(center->getX(), raio->getP2()->getY()), raio->getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(new Point(control->getX(), center->getY()), control);
				distanceAC = pointDistance(center, control);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 90 - angleB - angleG;
				incrementAngle = 90 + angleG;

				while (incrementAngle <= 180 - angleB) {

					points.push_back(findArchPoint(incrementAngle));

					incrementAngle += angle / 50;
				}
			}
			break;

		case 3:
			distanceEB = pointDistance(new Point(center->getX(), raio->getP2()->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(center->getX(), control->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 - angleB - angleG;
			incrementAngle = 90 + angleG;

			while (incrementAngle <= 270 - angleB)
			{
				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 100;
			}
			break;
		case 4:
			distanceEB = pointDistance(new Point(center->getX(), raio->getP2()->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(control->getX(), center->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 270 - angleB - angleG;
			incrementAngle = 90 + angleG;

			while (incrementAngle <= 360 - angleB) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 150;
			}
			break;
		}

		break;
	case 3:
		switch (quadrantControle) {
		case 1:
			distanceEB = pointDistance(new Point(raio->getP2()->getX(), center->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(center->getX(), control->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 270 - angleB - angleG;
			incrementAngle = 180 + angleG;

			while (incrementAngle <= 360 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 150;
			}
			break;
		case 2:
			distanceEB = pointDistance(new Point(raio->getP2()->getX(), center->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(control->getX(), center->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 360 - angleB - angleG;
			incrementAngle = 180 + angleG;

			while (incrementAngle <= 450 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 100;
			}
			break;
		case 3:

			if (raio->getP2()->getX() < control->getX())
			{
				distanceEB = pointDistance(new Point(raio->getP2()->getX(), center->getY()), raio->getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(new Point(center->getX(), control->getY()), control);
				distanceAC = pointDistance(center, control);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 90 - angleB - angleG;
				incrementAngle = 180 + angleG;

				while (incrementAngle <= 270 - angleB) {

					points.push_back(findArchPoint(incrementAngle));

					incrementAngle += angle / 150;
				}
			}
			else
			{
				distanceEB = pointDistance(new Point(center->getX(), raio->getP2()->getY()), raio->getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(new Point(control->getX(), center->getY()), control);
				distanceAC = pointDistance(center, control);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 270 + angleB + angleG;
				incrementAngle = 270 - angleG;

				while (incrementAngle <= 540 + angleB) {

					points.push_back(findArchPoint(incrementAngle));


					incrementAngle += angle / 200;
				}
			}

			break;
		case 4:
			distanceEB = pointDistance(new Point(raio->getP2()->getX(), center->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(control->getX(), center->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 - angleB - angleG;
			incrementAngle = 180 + angleG;

			while (incrementAngle <= 360 - angleB) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 50;
			}
			break;
		}
		break;
	case 4:
		switch (quadrantControle) {
		case 1:
			distanceEB = pointDistance(new Point(center->getX(), raio->getP2()->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(center->getX(), control->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 - angleB - angleG;
			incrementAngle = 270 + angleG;

			while (incrementAngle <= 360 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 100;
			}
			break;
		case 2:
			distanceEB = pointDistance(new Point(center->getX(), raio->getP2()->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(control->getX(), center->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 270 - angleB - angleG;
			incrementAngle = 270 + angleG;

			while (incrementAngle <= 450 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 150;
			}
			break;
		case 3:
			distanceEB = pointDistance(new Point(center->getX(), raio->getP2()->getY()), raio->getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = pointDistance(new Point(center->getX(), control->getY()), control);
			distanceAC = pointDistance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 + angleB + angleG;
			incrementAngle = 270 + angleG;

			while (incrementAngle <= 540 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 200;
			}
			break;
		case 4:
			if (raio->getP2()->getX() < control->getX())
			{
				distanceEB = pointDistance(new Point(center->getX(), raio->getP2()->getY()), raio->getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(new Point(control->getX(), center->getY()), control);
				distanceAC = pointDistance(center, control);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 90 - angleB - angleG;
				incrementAngle = 270 + angleG;

				while (incrementAngle <= 360 - angleB) {

					points.push_back(findArchPoint(incrementAngle));

					incrementAngle += angle / 50;
				}
			}
			else
			{
				distanceEB = pointDistance(new Point(raio->getP2()->getX(), center->getY()), raio->getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = pointDistance(new Point(center->getX(), control->getY()), control);
				distanceAC = pointDistance(center, control);
				angleB = getAngleArcSen(distanceDC, distanceAC);

				angle = 270 + angleB + angleG;
				incrementAngle = 360 - angleG;

				while (incrementAngle <= 630 + angleB) {

					points.push_back(findArchPoint(incrementAngle));

					incrementAngle += angle / 200;
				}
			}

		}
		break;
	}


	return points;
}


int Arch::getQuadrant(Point* p)
{
	if (p->getX() >= center->getX())
	{
		if (p->getY() <= center->getY())
			return 1;

		else
			return 4;
	}
	else if (p->getX() < center->getX())
	{
		if (p->getY() <= center->getY())
			return 2;

		else
			return 3;
	}
}
