#include "Arch.h"
#define _USE_MATH_DEFINES
#include <math.h>

double Arch::getAngleArcSen(double cateto, double hipotenusa) {
	return asin(cateto / hipotenusa) * 180 / M_PI;
}

Point Arch::findArchPoint(double auxAngle) {
	double raioLenght = Point::distance(p1, p2);

	double ang = auxAngle * M_PI / 180;

	double auxX = cos(ang) * raioLenght;
	double auxY = sin(ang) * raioLenght;

	double a = p1.x + auxX;
	double b = p1.y - auxY;

	return Point(int(a), int(b));
}

std::vector<Point> Arch::getPoints()
{
	double raioLenght = Point::distance(p1, p2);
	double incrementAngle;

	std::vector<Point> points;
	points.push_back(p2);

   const int quadrantP2 = getQuadrant(p2);
   const int quadrantP3 = getQuadrant(p3);	

   double angle;
	double distanceEB;
	double distanceDC;
	double distanceAC;
	double angleG;
	double angleB;

	switch (quadrantP2)
	{
	case 1:
		switch (quadrantP3) {
		case 1:

			if (p2.x < p3.x) {
				distanceEB = Point::distance(Point(p1.x, p2.y), p2);
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(p3.x, p1.y), p3);
				distanceAC = Point::distance(p1, p3);
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
				distanceEB = Point::distance(Point(p2.x, p1.y), p2);
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(p1.x, p3.y), p3);
				distanceAC = Point::distance(p1, p3);
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

			distanceEB = Point::distance(Point(p2.x, p1.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p3.x, p1.y), p3);
			distanceAC = Point::distance(p1, p3);
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
			distanceEB = Point::distance(Point(p2.x, p1.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p1.x, p3.y), p3);
			distanceAC = Point::distance(p1, p3);
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

			distanceEB = Point::distance(Point(p2.x, p1.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p3.x, p1.y), p3);
			distanceAC = Point::distance(p1, p3);
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
		switch (quadrantP3) {
		case 1:

			distanceEB = Point::distance(Point(p1.x, p2.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p1.x, p3.y), p3);
			distanceAC = Point::distance(p1, p3);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 + (90 - angleG) + (90 - angleB);
			incrementAngle = 90 + angleG;

			while (incrementAngle <= 360 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 150;
			}

			break;

		case 2:

			if (p2.x < p3.x) {
				distanceEB = Point::distance(Point(p2.x, p1.y), p2);
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(p1.x, p3.y), p3);
				distanceAC = Point::distance(p1, p3);
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
				distanceEB = Point::distance(Point(p1.x, p2.y), p2);
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(p3.x, p1.y), p3);
				distanceAC = Point::distance(p1, p3);
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
			distanceEB = Point::distance(Point(p1.x, p2.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p1.x, p3.y), p3);
			distanceAC = Point::distance(p1, p3);
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
			distanceEB = Point::distance(Point(p1.x, p2.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p3.x, p1.y), p3);
			distanceAC = Point::distance(p1, p3);
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
		switch (quadrantP3) {
		case 1:
			distanceEB = Point::distance(Point(p2.x, p1.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p1.x, p3.y), p3);
			distanceAC = Point::distance(p1, p3);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 270 - angleB - angleG;
			incrementAngle = 180 + angleG;

			while (incrementAngle <= 360 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 150;
			}
			break;
		case 2:
			distanceEB = Point::distance(Point(p2.x, p1.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p3.x, p1.y), p3);
			distanceAC = Point::distance(p1,p3);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 360 - angleB - angleG;
			incrementAngle = 180 + angleG;

			while (incrementAngle <= 450 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 100;
			}
			break;
		case 3:

			if (p2.x < p3.x)
			{
				distanceEB = Point::distance(Point(p2.x, p1.y), p2);
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(p1.x,p3.y),p3);
				distanceAC = Point::distance(p1,p3);
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
				distanceEB = Point::distance(Point(p1.x, p2.y), p2);
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(p3.x, p1.y), p3);
				distanceAC = Point::distance(p1,p3);
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
			distanceEB = Point::distance(Point(p2.x, p1.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p3.x, p1.y),p3);
			distanceAC = Point::distance(p1, p3);
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
		switch (quadrantP3) {
		case 1:
			distanceEB = Point::distance(Point(p1.x, p2.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p1.x,p3.y),p3);
			distanceAC = Point::distance(p1,p3);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 - angleB - angleG;
			incrementAngle = 270 + angleG;

			while (incrementAngle <= 360 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 100;
			}
			break;
		case 2:
			distanceEB = Point::distance(Point(p1.x, p2.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p3.x, p1.y),p3);
			distanceAC = Point::distance(p1,p3);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 270 - angleB - angleG;
			incrementAngle = 270 + angleG;

			while (incrementAngle <= 450 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 150;
			}
			break;
		case 3:
			distanceEB = Point::distance(Point(p1.x, p2.y), p2);
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(p1.x,p3.y),p3);
			distanceAC = Point::distance(p1,p3);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 + angleB + angleG;
			incrementAngle = 270 + angleG;

			while (incrementAngle <= 540 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 200;
			}
			break;
		case 4:
			if (p2.x < p3.x)
			{
				distanceEB = Point::distance(Point(p1.x, p2.y), p2);
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(p3.x, p1.y),p3);
				distanceAC = Point::distance(p1,p3);
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
				distanceEB = Point::distance(Point(p2.x, p1.y), p2);
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(p1.x,p3.y),p3);
				distanceAC = Point::distance(p1,p3);
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


int Arch::getQuadrant(const Point& p)
{
	if (p.x >= p1.x) {
		if (p.y <= p1.y)
			return 1;

		return 4;
	}

   if ((p.x < p1.x) && (p.y <= p1.y))
 	   return 2;
 
   return 3;
}
