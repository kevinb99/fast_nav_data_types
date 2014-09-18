#include "Point2DPolar.h"

Point2DPolar::Point2DPolar(double _radius, double _theta)
{
	radius = _radius;
	theta = _theta;
	while(theta > 2*PI)
		theta -= 2*PI;
	while(theta < 0)
		theta += 2*PI;
};

Point2DPolar::Point2DPolar(double x, double y, bool continious)
{
	radius = sqrt(pow(x,2)+pow(y,2));
	theta = atan2(y,x);
	while(theta > 2*PI)
		theta -= 2*PI;
	while(theta < 0)
		theta += 2*PI;
};

Point2DPolar::Point2DPolar(){};

Point2DPolar::~Point2DPolar(){};

double Point2DPolar::getRadius()
{
	return radius;
}

double Point2DPolar::getTheta()
{
	return theta;
}