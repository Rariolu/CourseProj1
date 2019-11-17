#ifndef _SPHERECOLLIDER_H
#define _SPHERECOLLIDER_H

#include "Aliases.h"
#include "Collider.h"

class SphereCollider : public Collider
{
	public:
		SphereCollider(Vec3* pos, float r);
		bool CollidesWith(Collider* other);
		bool CollidesWith(SphereCollider* other);
		float GetRadius();
	private:
		
		
		float radius;
};

#endif