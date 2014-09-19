#include "Pose3DDiscrete.h"

Pose3DDiscrete::Pose3DDiscrete(Pose2D* pose, int _z, double _rho, double _phi) : Pose2D(pose, pose->getOrientation())
{
	z = _z;
	rho = _rho;
	phi = _phi;
}

int Pose3DDiscrete::getDZ()
{
	return z;
}

Pose3DDiscrete::~Pose3DDiscrete(){};

double Pose3DDiscrete::getRho()
{
	return rho;
}

double Pose3DDiscrete::getPhi()
{
	return phi;
}