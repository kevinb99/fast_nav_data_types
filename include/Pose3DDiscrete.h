#ifndef POSE3DDISCRETE
#define POSE3DDISCRETE

#include "Pose2D.h"

class Pose3DDiscrete : public Pose2D
{
public:
	Pose3DDiscrete(Pose2D* pose, int _z, double _rho, double _phi);
	~Pose3DDiscrete();
	
	int getDZ();
	double getRho();
	double getPhi();

protected:
	int z;
	double rho,phi;
};

#endif