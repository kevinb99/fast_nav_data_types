#ifndef POINT2DCONTINIOUS
#define POINT2DCONTINIOUS

#include "math+.h"

using namespace fast_nav;

class Point2DContinious
{
public:
	Point2DContinious(double _x, double _y);
	~Point2DContinious();

	double getX();
	double getY();

protected:
	double x,y;
	
	Point2DContinious();
};

#endif
