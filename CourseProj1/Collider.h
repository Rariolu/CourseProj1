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
		Collider(COLLIDERTYPE type);
		virtual bool CollidesWith(Collider* other) = 0;
		COLLIDERTYPE ColliderType();
	private:
		COLLIDERTYPE colliderType;
};

#endif