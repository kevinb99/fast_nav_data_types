#ifndef VARIABLEAT
#define VARIABLEAT

#include "Point2D.h"

template<class T>
class VariableAt
{
public:
	VariableAt(Point2D* _at, T _variable);
	~VariableAt();

	Point2D* getHere();
	T getAt();
	
protected:
	T variable;
	Point2D* at;
};

#endif