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
T Grid2D<T>::getAt(Point2D* at)
{
	return grid[at->getDX()][at->getDY()];
}

template<class T>
T Grid2D<T>::getAt(VariableAt<T>* variable)
{
	variable = new VariableAt<T>(variable->getHere(), getAt(variable->getHere()));
	return variable->getAt();
}

template<class T>
std::vector<VariableAt<T>*> Grid2D<T>::getAt(std::vector<VariableAt<T>* > variables)
{
	for(int i=0; i<variables.size(); i++)
	{
		getAt(variables[i]);
	}
	return variables;
}

template<class T>
std::vector<VariableAt<T>*> Grid2D<T>::getAt(std::vector<Point2D* > ats)
{
	std::vector<VariableAt<T>*> atsVars = std::vector<VariableAt<T>* >(ats.size());
	for(int i=0; i<ats.size(); i++)
	{
		atsVars[i] = new VariableAt<T>(ats[i], getAt(ats[i]));
	}
	return atsVars;
}

template<class T>
void Grid2D<T>::setAt(VariableAt<T>* variable)
{
	grid[variable->getHere()->getDX()][variable->getHere()->getDY()] = variable->getVariable();
}

template<class T>
void Grid2D<T>::setAt(std::vector<VariableAt<T>* > variables)
{
	for(int i=0; i<variables.size(); i++)
	{
		setAt(variables[i]);
	}
}
/*
template<class T>
void Grid2D<T>::addAt(VariableAt<T>* variable);
{
	VariableAt<T>* var = new VariableAt<T>(variable->getHere(), variable->getVariable()+getAt(variable));
	setAt(var);
}

template<class T>
void Grid2D<T>::addAt(std::vector<VariableAt<T>* > variables)
{
	for(int i=0; i<variables.size(); i++)
	{
		addAt(variables[i]);
	}
}		
*/