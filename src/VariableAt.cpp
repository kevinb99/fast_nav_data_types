#include "VariableAt.h"


template<class T>
VariableAt<T>::VariableAt(Point2D* _at, T _variable)
{
	at = _at;
	variable = _variable;
};


template<class T>
Point2D* VariableAt<T>::getHere()
{
	return at;
}

template<class T>
T VariableAt<T>::getAt()
{
	return variable;
}