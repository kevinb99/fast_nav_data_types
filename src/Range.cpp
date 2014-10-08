#include "Range.h"

Range::Range(double _min, double _max)
{
	if(_min <= _max)
	{
		min = _min;
		max = _max;
	}
	else
	{
		min = _max;
		max = _min;
	}
}


bool Range::inRange(double value)
{
	if(value >= min && value <= max)
		return true;
	return false;
}

double Range::getMin()
{
	return min;
}

double Range::getMax()
{
	return max;
}

double Range::delta()
{
	return fabs(max-min);
}