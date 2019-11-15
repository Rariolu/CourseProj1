#ifndef _COLLIDER_H
#define _COLLIDER_H

#include "Util.h"

enum class COLLIDERTYPE
{
	SPHERE,
	BOX
};

class Collider
{
	public:
		Collider(COLLIDERTYPE type, Vec3* pos);
		virtual bool CollidesWith(Collider* other) = 0;
		COLLIDERTYPE ColliderType();
		Vec3 GetPosition();
	private:
		COLLIDERTYPE colliderType;
		Vec3* position;
};

#endif