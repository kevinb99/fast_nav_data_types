#include "BoolGrid2D.h"
#include "CenteredGrid2D.cpp"
#include "VariableAt.cpp"

BoolGrid2D::BoolGrid2D(int x, int y, double _resolution) : CenteredGrid2D<bool>(x, y, false)
{
	edited = false;
	resolution = _resolution;
};

BoolGrid2D::BoolGrid2D(int size, double _resolution) : CenteredGrid2D<bool>(size, false)
{
	edited = false;
	resolution = _resolution;
};

/*
	will not throw errors even if outside bounds
*/
void BoolGrid2D::setAt(VariableAt<bool>* vat)
{
	bool currentVal;
	try
	{
		currentVal = getAt(vat);
	}
	catch (int e)
	{
		return; //if out of bounds just give up
	}

	if(currentVal!= vat->getAt())
	{
		edited = true;
	}

	CenteredGrid2D<bool>::setAt(vat);
}

void BoolGrid2D::setAt(std::vector<VariableAt<bool>* > vats)
{
	#pragma omp parallel for
	for(int i=0; i<vats.size(); i++)
	{
		setAt(vats[i]);
	}
}