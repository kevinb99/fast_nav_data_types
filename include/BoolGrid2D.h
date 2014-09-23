#ifndef BOOLGRID2D 
#define BOOLGRID2D
#include "CenteredGrid2D.h"
//#include "Grid2D.cpp"

class BoolGrid2D : public CenteredGrid2D<bool>
{
public:
	BoolGrid2D(int x, int y);
	~BoolGrid2D();
	
};

#endif