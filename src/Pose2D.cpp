#include "Pose2D.h"

Pose2D::Pose2D(Point2D* point, double _orientation) : Point2D(point)
{
	orientation = _orientation;
	orientation = bound2PI(orientation);
};

double Pose2D::getOrientation()
{
	return orientation;
}

Pose2D::~Pose2D(){};