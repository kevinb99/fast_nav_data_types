#include "ControledVariable.h"

template<class T>
ControledVariable<T>::ControledVariable(T _variable)
{
	variable = _variable;
	state = INIT;
};

template<class T>
ControledVariable<T>::ControledVariable()
{
	state = PREINIT;
}

template<class T>
void ControledVariable<T>::setVariable(T value)
{
	variable = value;
	state = SET;
}

template<class T>
controlStates ControledVariable<T>::variableState()
{
	return state;
}

template<class T>
bool ControledVariable<T>::isSet()
{
	if(state == SET)
		return true;
	return false;
}

template<class T>
T ControledVariable<T>::getVariable()
{
	if(state != SET)
		return NULL;
	return variable;
}