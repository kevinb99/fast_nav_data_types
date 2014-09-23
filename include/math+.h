#ifndef MATHS

#define MATHS

#include <math.h>
#include <cstddef>
#include <iostream>
#include "ros/ros.h"

namespace fast_nav
{
	# define PI           3.14159265358979323846  /* pi */

	double round(double a)
	{
		return floor(a+0.5);
	}

	double bound2PI(double value)
	{
		while(value > 2*PI)
			value -= 2*PI;
		while(value < 0)
			value += 2*PI;
		return value;		
	}
}

using namespace fast_nav;

#endif