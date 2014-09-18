#include "Point2D.h"
#include "ros/ros.h"
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Point_Test");

	ros::NodeHandle n;

	/*
	Point2DDiscrete* dp = new Point2DDiscrete(2,2,1);
	Point2D* p = new Point2D(dp);
	*/
	Point2D* p = new Point2D(new Point2DDiscrete(2,2,1));
	Point2DDiscrete* notDP = p;
	Point2DContinious* cp = p;
	Point2DPolar* pp = p;

	//std::cout << "radius:" << pp->getRadius() << " theta:" << pp->getTheta() << "\n";

	if(notDP->getX() == 2 && cp->getX() == 2 && pp->getRadius() == sqrt(8) && pp->getTheta() == PI/4)
		std::cout << "it worked I have created the everything 2D point :D\n";

	return 0;
}