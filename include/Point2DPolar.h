#ifndef POINT2DPOLAR
#define POINT2DPOLAR 

#include "math+.h"

using namespace fast_nav;

class Point2DPolar
{
public:
	Point2DPolar(double _radius, double _theta);
	Point2DPolar(double x, double y, bool continious);
	~Point2DPolar();

	double getRadius();
	double getTheta();

protected:
	double radius,theta;

	Point2DPolar();


};

#endif
