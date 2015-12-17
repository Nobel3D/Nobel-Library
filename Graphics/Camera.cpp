#include "Camera.h"
#include <gtc\matrix_transform.hpp>

using namespace glm;
using namespace NobelLib::Graphics;
using namespace NobelLib;

Camera::Camera()
{
	cam_pPosition = Point3(0,0,0);
	cam_pCenterObject = Point3(0, 0, 0);
	cam_pUpObject = Point3(0, 0, 0);
	cam_fNear = 0.f;
	cam_fFar = 0.f;
}

Camera::Camera(Point3 position, Point3 center, Point3 up, NFloat _near, NFloat _far)
{
	setPosition(position);
	setTarget(center, up);
	setLimits(_near, _far);
}

RESULT Camera::setPosition(Point3 position)
{
	cam_pPosition = position;

	return 1;
}

RESULT Camera::setTarget(Point3 center, Point3 up)
{
	cam_pCenterObject = center;
	cam_pUpObject = up;

	return 1;
}

RESULT Camera::setLimits(NFloat _near, NFloat _far)
{
	cam_fNear = _near;
	cam_fFar = _far;
	return 1;
}

mat4 Camera::lookAt()
{
	return glm::lookAt(cam_pPosition.toVec3(),			//camera position;
					   cam_pCenterObject.toVec3(),		//look origins
					   cam_pUpObject.toVec3());			//head position
}

mat4 Camera::ortho(NFloat left, NFloat right, NFloat bottom, NFloat top)
{
	return glm::ortho((float)left, (float)right, (float)bottom, (float)top, 0.0f, 100.0f);
}

mat4 Camera::projection(NFloat FoV_angle)
{
	return glm::perspective((float)FoV_angle, (float)GLObject::scr_cResolution.scr_fRatio, 0.1f, 100.0f);
}