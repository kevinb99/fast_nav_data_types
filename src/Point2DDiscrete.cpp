#include "Point2DDiscrete.h"

Point2DDiscrete::Point2DDiscrete(int _x, int _y, double _resolution)
{
	x = _x;
	y = _y;
	resolution = _resolution;
};

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
