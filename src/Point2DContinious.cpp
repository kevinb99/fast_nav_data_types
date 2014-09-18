#include "Point2DContinious.h"

Point2DContinious::Point2DContinious(double _x, double _y)
{
	x = _x;
	y = _y;
};

Point2DContinious::Point2DContinious(){};

Point2DContinious::~Point2DContinious(){};

double Point2DContinious::getX()
{
	return x;
}

double Point2DContinious::getY()
{
	return y;
}
