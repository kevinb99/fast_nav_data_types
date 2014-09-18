#ifndef POINT2DDISCRETE

#define POINT2DDISCRETE 

#include "math+.h"

using namespace fast_nav;

class Point2DDiscrete
{
public:
	Point2DDiscrete(int _x, int _y, double _resolution);
	Point2DDiscrete(double _x, double _y, double _resolution);
	~Point2DDiscrete();

	int getX();
	int getY();
	double getResolution();

protected:
	int x,y;
	double resolution;

	Point2DDiscrete();
};

#endif
