#include "math+.h"

class Point2DRadial
{
public:
	Point2DRadial(double _radius, double _theta);
	~Point2DRadial();

protected:
	double radius,theta;

	double getRadius();
	double getTheta();
};