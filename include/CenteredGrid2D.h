#ifndef CENTEREDGRID2D
#define CENTEREDGRID2D

#include "Grid2D.h"

template<class T>
class CenteredGrid2D : public Grid2D<T>
{
public:
	CenteredGrid2D(int x, int y, T value);
	CenteredGrid2D(int x, int y, int _xOffset, int _yOffset);
	CenteredGrid2D(int x, int y, int _xOffset, int _yOffset, T value);
	CenteredGrid2D(int size, T value);
	CenteredGrid2D(std::vector<std::vector<T> > _grid);
	~CenteredGrid2D();

	T getAt(Point2D* at);
	std::vector<VariableAt<T>*> getAt(std::vector<Point2D*> ats);
	void setAt(VariableAt<T>* variable);
	void setAt(Point2D* at, T value);
	void setAt(std::vector<VariableAt<T>* > variables);
	/* some data types may not work with this method*/
	void addAt(VariableAt<T>* variable);
	void addAt(Point2D* at, T value);
	void addAt(std::vector<VariableAt<T>* > variables);

	bool isInGrid(Point2D* at);

protected:
	int xOffset, yOffset; //positive numbers are subtracted to apply offset
	
	VariableAt<T>* applyOffsets(VariableAt<T>* variable);
	std::vector<VariableAt<T>*> applyOffsets(std::vector<VariableAt<T>*> variables);
};

#endif