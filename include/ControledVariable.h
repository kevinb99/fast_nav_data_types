
#ifndef CONTROLEDVARIABLE
#define CONTROLEDVARIABLE

#include "math+.h" 

enum controlStates
{
	PREINIT, INIT, SET
};

template<class T>
class ControledVariable
{
public:
	ControledVariable(T _variable);
	ControledVariable();
	~ControledVariable();

	void setVariable(T value);
	controlStates variableState();
	bool isSet();
	T getVariable();

protected:
	T variable;
	controlStates state;
};

#endif