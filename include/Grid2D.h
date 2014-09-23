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
	Grid2D(int x, int y, T value);
	Grid2D(std::vector<std::vector<T> > _grid);
	~Grid2D();

	T getAt(Point2D* at);
	std::vector<VariableAt<T>*> getAt(std::vector<Point2D*> ats);
	void setAt(VariableAt<T>* variable);
	void setAt(std::vector<VariableAt<T>* > variables);
	std::vector<std::vector<T> > getGrid();
	/* some data types may not work with this method*/
	void addAt(VariableAt<T>* variable);
	void addAt(std::vector<VariableAt<T>* > variables);

	int getWidth();
	int getHeight();
	
protected:
	std::vector<std::vector<T> > grid;

	bool isInGrid(Point2D* at);
};

#endif