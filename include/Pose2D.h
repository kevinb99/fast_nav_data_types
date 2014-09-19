#ifndef POSE2D
#define POSE2D 

#include "Point2D.h"

class Pose2D : public Point2D
{
public:
	Pose2D(Point2D* point, double _orientation);
	~Pose2D();

	double getOrientation();

protected:
	double orientation;
};

#endif