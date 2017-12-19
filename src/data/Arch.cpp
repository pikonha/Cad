#include "Arch.h"
#include "Line.h"
#define _USE_MATH_DEFINES
#include <math.h>


Arch::Arch(const Point& _p1, const Point& _p2, const Point& _p3) : Geometry(_p1,_p2)
{
	p3= _p3;
	raio= Line(_p1, _p2);
	center= _p1;
	control= _p2;
}



double Arch::getAngleArcSen(double cateto, double hipotenusa) {
	return asin(cateto / hipotenusa) * 180 / M_PI;
}

Point Arch::findArchPoint(double auxAngle) {
	double raioLenght = Point::distance(raio.getP1(), raio.getP2());

	double ang = auxAngle * M_PI / 180;

	double auxX = cos(ang) * raioLenght;
	double auxY = sin(ang) * raioLenght;

	double a = center.x + auxX;
	double b = center.y - auxY;

	return Point(int(a), int(b));
}

std::vector<Point> Arch::getPoints()
{
	double raioLenght = Point::distance(raio.getP1(), raio.getP2());
	double incrementAngle;

	std::vector<Point> points;
	points.push_back(raio.getP2());

	int quadrantControle = getQuadrant(control);
	int quadrantB = getQuadrant(raio.getP2());

	double distanceEB;
	double distanceDC;
	double distanceAC;
	double angleG;
	double angleB;

	switch (quadrantB)
	{
	case 1:
		switch (quadrantControle) {
		case 1:

			if (raio.getP2().x < control.x) {
				distanceEB = Point::distance(Point(center.x, raio.getP2().y), raio.getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(control.x, center.y), control);
				distanceAC = Point::distance(center, control);
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
				distanceEB = Point::distance(Point(raio.getP2().x, center.y), raio.getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(center.x, control.y), control);
				distanceAC = Point::distance(center, control);
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

			distanceEB = Point::distance(Point(raio.getP2().x, center.y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(control.x, center.y), control);
			distanceAC = Point::distance(center, control);
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
			distanceEB = Point::distance(Point(raio.getP2().x, center.y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(center.x, control.y), control);
			distanceAC = Point::distance(center, control);
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

			distanceEB = Point::distance(Point(raio.getP2().x, center.y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(control.x, center.y), control);
			distanceAC = Point::distance(center, control);
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

			distanceEB = Point::distance(Point(center.x, raio.getP2().y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(center.x, control.y), control);
			distanceAC = Point::distance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 + (90 - angleG) + (90 - angleB);
			incrementAngle = 90 + angleG;

			while (incrementAngle <= 360 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 150;
			}

			break;

		case 2:

			if (raio.getP2().x < control.x) {
				distanceEB = Point::distance(Point(raio.getP2().x, center.y), raio.getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(center.x, control.y), control);
				distanceAC = Point::distance(center, control);
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
				distanceEB = Point::distance(Point(center.x, raio.getP2().y), raio.getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(control.x, center.y), control);
				distanceAC = Point::distance(center, control);
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
			distanceEB = Point::distance(Point(center.x, raio.getP2().y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(center.x, control.y), control);
			distanceAC = Point::distance(center, control);
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
			distanceEB = Point::distance(Point(center.x, raio.getP2().y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(control.x, center.y), control);
			distanceAC = Point::distance(center, control);
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
			distanceEB = Point::distance(Point(raio.getP2().x, center.y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(center.x, control.y), control);
			distanceAC = Point::distance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 270 - angleB - angleG;
			incrementAngle = 180 + angleG;

			while (incrementAngle <= 360 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 150;
			}
			break;
		case 2:
			distanceEB = Point::distance(Point(raio.getP2().x, center.y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(control.x, center.y), control);
			distanceAC = Point::distance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 360 - angleB - angleG;
			incrementAngle = 180 + angleG;

			while (incrementAngle <= 450 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 100;
			}
			break;
		case 3:

			if (raio.getP2().x < control.x)
			{
				distanceEB = Point::distance(Point(raio.getP2().x, center.y), raio.getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(center.x, control.y), control);
				distanceAC = Point::distance(center, control);
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
				distanceEB = Point::distance(Point(center.x, raio.getP2().y), raio.getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(control.x, center.y), control);
				distanceAC = Point::distance(center, control);
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
			distanceEB = Point::distance(Point(raio.getP2().x, center.y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(control.x, center.y), control);
			distanceAC = Point::distance(center, control);
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
			distanceEB = Point::distance(Point(center.x, raio.getP2().y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(center.x, control.y), control);
			distanceAC = Point::distance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 - angleB - angleG;
			incrementAngle = 270 + angleG;

			while (incrementAngle <= 360 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 100;
			}
			break;
		case 2:
			distanceEB = Point::distance(Point(center.x, raio.getP2().y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(control.x, center.y), control);
			distanceAC = Point::distance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 270 - angleB - angleG;
			incrementAngle = 270 + angleG;

			while (incrementAngle <= 450 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 150;
			}
			break;
		case 3:
			distanceEB = Point::distance(Point(center.x, raio.getP2().y), raio.getP2());
			angleG = getAngleArcSen(distanceEB, raioLenght);

			distanceDC = Point::distance(Point(center.x, control.y), control);
			distanceAC = Point::distance(center, control);
			angleB = getAngleArcSen(distanceDC, distanceAC);

			angle = 180 + angleB + angleG;
			incrementAngle = 270 + angleG;

			while (incrementAngle <= 540 + (90 - angleB)) {

				points.push_back(findArchPoint(incrementAngle));

				incrementAngle += angle / 200;
			}
			break;
		case 4:
			if (raio.getP2().x < control.x)
			{
				distanceEB = Point::distance(Point(center.x, raio.getP2().y), raio.getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(control.x, center.y), control);
				distanceAC = Point::distance(center, control);
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
				distanceEB = Point::distance(Point(raio.getP2().x, center.y), raio.getP2());
				angleG = getAngleArcSen(distanceEB, raioLenght);

				distanceDC = Point::distance(Point(center.x, control.y), control);
				distanceAC = Point::distance(center, control);
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
	if (p.x >= center.x) {
		if (p.y <= center.y)
			return 1;

		return 4;
	}

   if ((p.x < center.x) && (p.y <= center.y))
 	   return 2;
 
   return 3;
}
