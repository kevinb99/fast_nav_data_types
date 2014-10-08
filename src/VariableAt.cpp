#ifndef VARIABLEATCPP
#define VARIABLEATCPP
#include "VariableAt.h"


template<class T>
VariableAt<T>::VariableAt(Point2D* _at, T _variable) : Point2D(_at)
{
	variable = _variable;
};

template<class T>
VariableAt<T>::VariableAt(Point2D* _at) : Point2D(_at){};

template<class T>
VariableAt<T>::~VariableAt(){};

template<class T>
T VariableAt<T>::getAt()
{
	return variable;
}

#endif