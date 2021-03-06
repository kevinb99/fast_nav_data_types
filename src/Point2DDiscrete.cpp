#include "Point2DDiscrete.h"

using namespace fast_nav;

Point2DDiscrete::Point2DDiscrete(int _x, int _y, double _resolution)
{
	x = _x;
	y = _y;
	resolution = _resolution;
};

Point2DDiscrete::Point2DDiscrete(double _x, double _y, double _resolution)
{
	x = fast_nav::round(_x/_resolution);
	y = fast_nav::round(_y/_resolution);
	resolution = _resolution;
}

Point2DDiscrete::Point2DDiscrete(){};

Point2DDiscrete::~Point2DDiscrete(){};

int Point2DDiscrete::getDX()
{
	return x;
}

int Point2DDiscrete::getDY()
{
	return y;
}

double Point2DDiscrete::getResolution()
{
	return resolution;
}
