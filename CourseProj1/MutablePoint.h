#ifndef _MUTABLEPOINT_H
#define _MUTABLEPOINT_H

#include "Aliases.h"

enum class AXIS
{
	X, Y, Z
};

//A struct representing a specific object
//in 3D space which can be moved around
//(may add rotation later).
struct MutablePoint
{
	public:
		virtual Vec3* GetPosition();
		virtual void SetPosition(float x, float y, float z);
		virtual void SetPosition(Vec3 position);
		virtual void Translate(AXIS axis, float t);
	protected:
		Vec3 position;
};

#endif