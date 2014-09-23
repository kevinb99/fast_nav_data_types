#include "Grid2D.h"

template<class T>
Grid2D<T>::Grid2D(int x, int y)
{
	grid = std::vector<std::vector<T> >(x, std::vector<T>(y));
};

template<class T>
Grid2D<T>::Grid2D(int x, int y, T value)
{
	grid = std::vector<std::vector<T> >(x, std::vector<T>(y));
	#pragma omp parallel for
	for(int cy=0; cy<y; cy++)
	{
		for(int cx=0; cx<x; cx++)
		{
			grid[cx][cy] = value;
		}
	}
};

template<class T>
Grid2D<T>::Grid2D(std::vector<std::vector<T> > _grid)
{
	grid = _grid;
};

template<class T>
Grid2D<T>::~Grid2D()
{
};

template<class T>
T Grid2D<T>::getAt(Point2D* at)
{
	//ROS_DEBUG("geting from base grid");
	return grid[at->getDX()][at->getDY()];
}

template<class T>
std::vector<VariableAt<T>*> Grid2D<T>::getAt(std::vector<Point2D*> ats)
{
	std::vector<VariableAt<T>*> vars = std::vector<VariableAt<T>*>(ats.size());
	#pragma omp parallel for
	for(int i=0; i<ats.size(); i++)
	{
		vars[i] = new VariableAt<T>(ats[i], getAt(ats[i]));
	}
	return vars;
}

template<class T>
void Grid2D<T>::setAt(VariableAt<T>* variable)
{
	if(isInGrid(variable))
		grid[variable->getDX()][variable->getDY()] = variable->getAt();
}

template<class T>
void Grid2D<T>::setAt(std::vector<VariableAt<T>* > variables)
{
	#pragma omp parallel for
	for(int i=0; i<variables.size(); i++)
	{
		setAt(variables[i]);
	}
}

template<class T>
void Grid2D<T>::addAt(VariableAt<T>* variable)
{
	VariableAt<T>* var = new VariableAt<T>(variable, variable->getAt()+getAt(variable));
	setAt(var);
}

template<class T>
void Grid2D<T>::addAt(std::vector<VariableAt<T>* > variables)
{
	#pragma omp parallel for
	for(int i=0; i<variables.size(); i++)
	{
		addAt(variables[i]);
	}
}		

template<class T>
bool Grid2D<T>::isInGrid(Point2D* at)
{
	if(grid.size() < 1 || grid[0].size() < 1 || 
		at->getDX() < 0 || at->getDX() > grid.size() || 
		at->getDY() < 0 || at->getDY() > grid[0].size())
		return false;
	return true;
}

template<class T>
int Grid2D<T>::getWidth()
{
	return grid.size();
}

template<class T>
int Grid2D<T>::getHeight()
{
	if(grid.size() < 1)
		return 0;
	return grid[0].size();
}