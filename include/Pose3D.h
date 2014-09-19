#ifndef POSE3D
#define POSE3D

#include "Pose3DDiscrete.h"

class Pose3D : public Pose3DDiscrete
{
public:
	Pose3D(Pose3DDiscrete* pd);
	Pose3D(Pose2D* pose, double _z, double rho, double phi);
	~Pose3D();

	double getZ();
	
protected:
	double z;
};


#endif