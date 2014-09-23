#ifndef VARIABLEAT
#define VARIABLEAT

#include "Point2D.h"

template<class T>
class VariableAt : public Point2D
{
public:
	VariableAt(Point2D* _at, T _variable);
	VariableAt(Point2D* _at);
	~VariableAt();

	T getAt();
	
protected:
	T variable;
};

#endif