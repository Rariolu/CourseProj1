#ifndef _SPHERECOLLIDER_H
#define _SPHERECOLLIDER_H

#include "Aliases.h"
#include "Collider.h"

class SphereCollider : public Collider
{
	public:
		SphereCollider(Vec3* pos, float r);
		bool CollidesWith(Collider* other);
		Vec3 GetPosition();
		float GetRadius();
	private:
		bool CollidesWith(SphereCollider* other);
		Vec3* position;
		float radius;
};

#endif