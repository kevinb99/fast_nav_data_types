#include "Pose3D.h"

Pose3D::Pose3D(Pose3DDiscrete* pd) : Pose3DDiscrete(pd, pd->getDZ(), pd->getRho(), pd->getPhi())
{
	z = pd->getDZ()*pd->getResolution();
};

Pose3D::Pose3D(Pose2D* pose, double _z, double _rho, double _phi) : Pose3DDiscrete(pose, fast_nav::round(_z/pose->getResolution()), _rho, _phi)
{
	z = _z;
};
