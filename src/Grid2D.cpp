#include "Grid2D.h"

template<class T>
Grid2D<T>::Grid2D(int x, int y)
{
	grid = std::vector<std::vector<T> >(x, std::vector<T>(y));
}

template<class T>
Grid2D<T>::Grid2D(std::vector<std::vector<T> > _grid)
{
	grid = _grid;
}

template<class T>
T Grid2D<T>::getAt(Point2D* at)
{
	return grid[at->getDX()][at->getDY()];
}

template<class T>
T Grid2D<T>::getAt(VariableAt<T>* variable)
{
	variable = new VariableAt<T>(variable->getHere, getAt(variable->getHere));
	return variable->getAt();
}

template<class T>
void Grid2D<T>::setAt(VariableAt<T>* variable)
{
	grid[variable->getHere()->getDX()][variable->getHere()->getDY()] = variable->getVariable();
}