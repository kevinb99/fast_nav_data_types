#ifndef RANGE_H
#define RANGE_H

#include "math+.h"

class Range
{
public:
	Range(double _min, double _max);
	~Range();

	bool inRange(double value);
	double getMin();
	double getMax();
	double delta();
	
protected:
	double min, max;	
};

#endif