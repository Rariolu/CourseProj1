#ifndef _CAMERA_H
#define _CAMERA_H

#include <gtx/transform.hpp>
#include "Aliases.h"
#include "MutablePoint.h"

class Camera : public MutablePoint
{
	public:
		Camera(float fieldOfView, float aspectRatio, float nearClip, float farClip, Vec3 pos = Vec3(0,0,0));
		Vec3* GetForward();
		Vec3* GetUp();
		Matrix GetViewProjection() const;
	private:
		Matrix projection;
		Vec3 forward;
		Vec3 up;
};

#endif