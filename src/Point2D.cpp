#include "Point2D.h"

Point2D::Point2D(Point2DPolar* _polar, double resolution) : Point2DPolar(_polar->getRadius(), _polar->getTheta()), Point2DDiscrete( fast_nav::round(cos(_polar->getTheta())*_polar->getRadius()), fast_nav::round(sin(_polar->getTheta())*_polar->getRadius()), resolution), Point2DContinious(cos(_polar->getTheta())*_polar->getRadius(),sin(_polar->getTheta())*_polar->getRadius())
{
	
};

Point2D::Point2D(Point2DDiscrete* _discrete) : Point2DPolar(_discrete->getDX()*_discrete->getResolution(), _discrete->getDY()*_discrete->getResolution(), true), Point2DDiscrete(_discrete->getDX(), _discrete->getDY(), _discrete->getResolution()), Point2DContinious(_discrete->getDX()*_discrete->getResolution(), _discrete->getDY()*_discrete->getResolution())
{

};

Point2D::Point2D(Point2DContinious* _continious, double resolution) : Point2DPolar(_continious->getX(), _continious->getY(), true), Point2DDiscrete(_continious->getX(), _continious->getY(), resolution), Point2DContinious(_continious->getX(), _continious->getY())
{
	
};

Point2D::Point2D(int _x, int _y, double _resolution) : Point2DPolar(_x*_resolution, _y*_resolution, true), Point2DDiscrete(_x, _y, _resolution), Point2DContinious(_x*_resolution, _y*_resolution)
{
	
};

Point2D::~Point2D(){};

Point2D::Point2D(double _x, double _y, double resolution) : Point2DPolar(_x, _y, true), Point2DDiscrete(_x, _y, resolution), Point2DContinious(_x, _y)
{
	/*
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
	*/
	
};

/*

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

/*
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
*/
/*
using namespace fast_nav;
double round(double val)
{
	return fast_nav::round(val);
}
*/