#include "Point2DDiscrete.h"

Point2DDiscrete::Point2DDiscrete(int _x, int _y, double _resolution)
{
	x = _x;
	y = _y;
	resolution = _resolution;
};

Point2DDiscrete::Point2DDiscrete(double _x, double _y, double _resolution)
{
	x = _x/_resolution;
	y = _y/_resolution;
	resolution = _resolution;
}

Point2DDiscrete::Point2DDiscrete(){};

Point2DDiscrete::~Point2DDiscrete(){};

int Point2DDiscrete::getX()
{
	return x;
}

int Point2DDiscrete::getY()
{
	return y;
}

double Point2DDiscrete::getResolution()
{
	return resolution;
}
