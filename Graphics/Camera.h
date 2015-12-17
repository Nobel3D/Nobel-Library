#pragma once
#include "NFloat.h"
#include "Point.h"
#include "OpenGL.h"
#include <glm.hpp>

using namespace glm;

namespace NobelLib
{
	namespace Graphics
	{
		class Camera
		{
		private:
			Point3 cam_pPosition;
			Point3 cam_pCenterObject;
			Point3 cam_pUpObject;
			NFloat cam_fNear, cam_fFar;
		public:
			Camera();
			Camera(Point3 position, Point3 center, Point3 up, NFloat _near, NFloat _far);

			RESULT setPosition(Point3 position);
			RESULT setTarget(Point3 center, Point3 up);
			RESULT setLimits(NFloat _near, NFloat _far);
			mat4 lookAt();
			mat4 ortho(NFloat left, NFloat right, NFloat bottom, NFloat top);
			mat4 projection(NFloat FoV_Angle);
		};
	}
}