#include "Point2DRadial.h"

Point2DRadial::Point2DRadial(double _radius, double _theta)
{
	radius = _radius;
	theta = _theta;
};

double Point2DRadial::getRadius()
{
	return radius;
}

double Point2DRadial::getTheta()
{
	return theta;
}