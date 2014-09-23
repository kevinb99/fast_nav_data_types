#ifndef POINT2D
#define POINT2D

#include "Point2DDiscrete.h"
#include "Point2DContinious.h"
#include "Point2DPolar.h"

using namespace fast_nav;

enum pointTypes
{
	POLAR, CONTINIOUS, DISCRETE	
};

class Point2D : public Point2DPolar, public Point2DDiscrete, public Point2DContinious
{
public:
	Point2D(Point2DPolar* _polar, double resolution);
	Point2D(Point2DDiscrete* _discrete);
	Point2D(Point2DContinious* _continious, double resolution);
	Point2D(int _x, int _y, double _resolution);
	Point2D(double _x, double _y, double resolution=1.0);
	~Point2D();

/*
	Point2DPolar* getPolar();
	Point2DContinious* getContinious();
	Point2DDiscrete* getDiscrete();
*/
/*
	double getX();
	double getY();
	int getDX();
	int getDY();
*/

protected:
	/*
	void init(Point2DPolar* _polar, double resolution);
	void init(Point2DDiscrete* _discrete);
	void init(Point2DContinious* _continious, double resolution);
	void init();

	Point2DPolar* polar;
	Point2DDiscrete* discrete;
	Point2DContinious* continious;
	*/
};


#endif
