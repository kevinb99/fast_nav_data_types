#ifndef GRID2D
#define GRID2D

#include "Point2D.h"
#include <vector>
#include "VariableAt.h"

template<class T>
class Grid2D
{
public:
	Grid2D(int x, int y);
	Grid2D(std::vector<std::vector<T> > _grid);
	~Grid2D();

	T getAt(Point2D* at);
	T getAt(VariableAt<T>* variable);
	void setAt(VariableAt<T>* variable);
	std::vector<std::vector<T> > getGrid();
	
protected:
	std::vector<std::vector<T> > grid;
};

#endif