#include "math+.h"

class Point2DDiscrete
{
public:
	Point2DDiscrete(int _x, int _y, double _resolution);
	~Point2DDiscrete();

protected:
	int x,y;
	double resolution;

	int getX();
	int getY();
	double getResolution();
};