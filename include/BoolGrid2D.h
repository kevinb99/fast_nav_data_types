#ifndef BOOLGRID2D 
#define BOOLGRID2D
#include "CenteredGrid2D.h"
//#include "Grid2D.cpp"

class BoolGrid2D : public CenteredGrid2D<bool>
{
public:
	BoolGrid2D(int x, int y, double _resolution);
	BoolGrid2D(int size, double _resolution);
	~BoolGrid2D();

	void setAt(VariableAt<bool>* vat);
	void setAt(std::vector<VariableAt<bool>* > vats);

protected:
	bool edited;
	double resolution;
};

#endif