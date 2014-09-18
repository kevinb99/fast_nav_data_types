#include "math+.h"

class Point2DContinious
{
public:
	Point2DContinious(double _x, double _y);
	~Point2DContinious();

protected:
	double x,y;

	double getX();
	double getY();
	
};