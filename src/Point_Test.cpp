#include "Pose3D.h"
#include "ros/ros.h"
#include "Grid2D.h"
//#include "Grid2D.cpp"
#include "BoolGrid2D.h"
#include "VariableAt.cpp"
#include "BoolGrid2D.cpp"
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
	Point2D* p2 = new Point2D(cp, p->getResolution());
	Point2D* p3 = new Point2D(pp, p->getResolution());
	Point2D* p4 = new Point2D(notDP->getDX(), notDP->getDY(), notDP->getResolution());
	Point2D* p5 = new Point2D(cp->getX(), cp->getY(), p->getResolution());

	//std::cout << "radius:" << pp->getRadius() << " theta:" << pp->getTheta() << "\n";

	if(notDP->getDX() == 2 && cp->getX() == 2 && pp->getRadius() == sqrt(8) && pp->getTheta() == PI/4)
		std::cout << "it worked I have created the everything 2D point :D\n";

	Pose2D* pos = new Pose2D(p, PI/2);

	if(pos->getOrientation() == PI/2)
		std::cout << "wonder what pos->getX() gives me:" << pos->getX() << "\n";

	Pose3D* pose3 = new Pose3D(pos, 1.5, PI, 2*PI);

	Grid2D<int>* grid = new Grid2D<int>(10, 10, 4);

	BoolGrid2D* boolGrid = new BoolGrid2D(5, 5);

	Point2D* atVar = new Point2D(-3,-3,1);
	//ROS_INFO("sending at var");
	bool testBool = boolGrid->getAt(atVar);

	bool addDoes = true + false;

	std::cout << "At (3,10) in bool grid there is " << std::boolalpha << boolGrid->getAt(atVar) << "\n";

	std::cout << "But what about addDoes? " << std::boolalpha << addDoes << "\n";

	VariableAt<bool>* addThis = new VariableAt<bool>(atVar, addDoes);

	boolGrid->addAt(addThis);

	std::cout << "Did that fix it? ";

	if(boolGrid->getAt(atVar))
		std::cout << "Yes\n";
	else
		std::cout << "No\n";

	std::cout << "I lived \n";

	return 0;
}