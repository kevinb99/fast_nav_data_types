#include "Point2D.h"

Point2D::Point2D(Point2DPolar* _polar, double resolution)
{
	polar = _polar;
	init(_polar, resolution);
};

Point2D::Point2D(Point2DDiscrete* _discrete)
{
	discrete = _discrete;
	init(_discrete);
};

Point2D::Point2D(Point2DContinious* _continious, double resolution)
{
	continious = _continious;
	init(_continious, resolution);
};

Point2D::Point2D(int _x, int _y, double _resolution) : Point2DDiscrete(_x, _y, _resolution)
{
	discrete = new Point2DDiscrete(_x, _y, _resolution);
	init(discrete);
};

Point2D::Point2D(double a, double b, double resolution,  pointTypes is)
{
	switch(is)
	{
		case POLAR:
		polar = new Point2DPolar(a,b);
		init(polar, resolution);
		break;
		case CONTINIOUS:
		continious = new Point2DContinious(a,b);
		init(continious, resolution);
		break;
		case DISCRETE:
		discrete = new Point2DDiscrete(a, b, resolution);
		init(discrete);
		break;
	}
}

Point2D::~Point2D(){};

void Point2D::init(Point2DPolar* _polar, double resolution)
{
	continious = new Point2DContinious(cos(_polar->getTheta())*_polar->getRadius(),sin(_polar->getTheta())*_polar->getRadius());
	discrete = new Point2DDiscrete(continious->getX(), continious->getY(), resolution);
	init();
}

void Point2D::init(Point2DDiscrete* _discrete)
{
	continious = new Point2DContinious(_discrete->getX()*_discrete->getResolution(), _discrete->getY()*_discrete->getResolution());
	polar = new Point2DPolar(continious->getX(), continious->getY(), true);
	init();
}

void Point2D::init(Point2DContinious* _continious, double resolution)
{
	discrete = new Point2DDiscrete(_continious->getX(), _continious->getY(), resolution);
	polar = new Point2DPolar(_continious->getX(), _continious->getY(), true);
	init();
}

void Point2D::init()
{
	Point2DDiscrete::x = discrete->getX();
	Point2DDiscrete::y = discrete->getY();
	Point2DDiscrete::resolution = discrete->getResolution();

	Point2DContinious::x = continious->getX();
	Point2DContinious::y = continious->getY();

	Point2DPolar::radius = polar->getRadius();
	Point2DPolar::theta = polar->getTheta();
}

Point2DPolar* Point2D::getPolar()
{
	return polar;
}

Point2DContinious* Point2D::getContinious()
{
	return continious;
}

Point2DDiscrete* Point2D::getDiscrete()
{
	return discrete;
}

double Point2D::getX()
{
	return Point2DContinious::getX();
}

double Point2D::getY()
{
	return Point2DContinious::getX();
}

int Point2D::getDX()
{
	return Point2DDiscrete::getX();
}

int Point2D::getDY()
{
	return Point2DDiscrete::getY();
}

using namespace fast_nav;
double round(double val)
{
	return fast_nav::round(val);
}