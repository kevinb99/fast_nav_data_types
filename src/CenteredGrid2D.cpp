#include "CenteredGrid2D.h"
#include "Grid2D.cpp"

template<class T>
CenteredGrid2D<T>::CenteredGrid2D(int x, int y, T value) : Grid2D<T>(x+1,y+1,value)
{
	xOffset = (x+1)/2;
	yOffset = (y+1)/2;
};

template<class T>
CenteredGrid2D<T>::CenteredGrid2D(int x, int y, int _xOffset, int _yOffset) : Grid2D<T>(x+1,y+1)
{
	xOffset = _xOffset;
	yOffset = _yOffset;
};

template<class T>
CenteredGrid2D<T>::CenteredGrid2D(int x, int y, int _xOffset, int _yOffset, T value) : Grid2D<T>(x+1,y+1,value)
{
	xOffset = _xOffset;
	yOffset = _yOffset;
};

template<class T>
CenteredGrid2D<T>::CenteredGrid2D(std::vector<std::vector<T> > _grid) : Grid2D<T>(_grid)
{	
	xOffset = Grid2D<T>::getWidth()/2;
	yOffset = Grid2D<T>::getHeight()/2;
};

template<class T>
CenteredGrid2D<T>::CenteredGrid2D(int size, T value) : Grid2D<T>(size+1, value)
{
	xOffset = Grid2D<T>::getWidth()/2;
	yOffset = Grid2D<T>::getHeight()/2;
};

template<class T>
CenteredGrid2D<T>::~CenteredGrid2D(){};

template<class T>
VariableAt<T>* CenteredGrid2D<T>::applyOffsets(VariableAt<T>* variable)
{
	//ROS_INFO("applying offset %d %d", xOffset, yOffset);
	return new VariableAt<T>(new Point2D(xOffset-variable->getDX(), yOffset-variable->getDY(), 
		variable->getResolution()), variable->getAt());
}

template<class T>
std::vector<VariableAt<T>*> CenteredGrid2D<T>::applyOffsets(std::vector<VariableAt<T>*> variables)
{
	std::vector<VariableAt<T>*> vars = std::vector<VariableAt<T>*>(variables.size());
	#pragma omp parrallel for 
	for(int i = 0; i < variables; i++)
	{
		vars[i] = applyOffsets(variables[i]);
	}
	return vars;
}

template<class T>
T CenteredGrid2D<T>::getAt(Point2D* at)
{
	return Grid2D<T>::getAt(applyOffsets(new VariableAt<T>(at)));
}

template<class T>
std::vector<VariableAt<T>*> CenteredGrid2D<T>::getAt(std::vector<Point2D*> ats)
{
	std::vector<VariableAt<T>*> vars = std::vector<VariableAt<T>*>(ats.size());
	#pragma omp parrallel for
	for (int i = 0; i < ats.size(); ++i)
	{
		vars[i] = new VariableAt<T>(ats[i]);
	}
	return Grid2D<T>::getAt(applyOffsets(vars));
}

template<class T>
void CenteredGrid2D<T>::setAt(Point2D* at, T value)
{
	setAt(new VariableAt<T>(at, value));
}

template<class T>
void CenteredGrid2D<T>::setAt(VariableAt<T>* variable)
{
	Grid2D<T>::setAt(applyOffsets(variable));
}

template<class T>
void CenteredGrid2D<T>::setAt(std::vector<VariableAt<T>* > variables)
{
	Grid2D<T>::setAt(applyOffsets(variables));
}

/* some data types may not work with this method*/
template<class T>
void CenteredGrid2D<T>::addAt(VariableAt<T>* variable)
{
	Grid2D<T>::addAt(applyOffsets(variable));
}

template<class T>
void CenteredGrid2D<T>::addAt(Point2D* at, T value)
{
	addAt(new VariableAt<T>(at, value));
}

template<class T>
void CenteredGrid2D<T>::addAt(std::vector<VariableAt<T>* > variables)
{
	Grid2D<T>::addAt(applyOffsets(variables));
}

template<class T>
bool CenteredGrid2D<T>::isInGrid(Point2D* at)
{
	Grid2D<T>::isInGrid(applyOffsets(new VariableAt<T>(at)));
}