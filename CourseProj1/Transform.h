#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include "Aliases.h"
#include <gtx/transform.hpp>
#include "MutablePoint.h"

struct Transform : public MutablePoint
{
	public:
		Transform();
		Matrix GetModel();
		Vec3* GetRotation();
		Vec3* GetScale();
		void Rotate(AXIS axis, float r);
		void SetRotation(float x, float y, float z);
		void SetRotation(Vec3 rotation);
		void SetScale(float x, float y, float z);
		void SetScale(Vec3 scale);
	private:
		Vec3 rotation;
		Vec3 scale;
};

#endif