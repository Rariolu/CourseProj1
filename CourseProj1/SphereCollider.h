#ifndef _SPHERECOLLIDER_H
#define _SPHERECOLLIDER_H

#include "Aliases.h"
#include "Collider.h"

//A collider which detects collisions within
//its spherical shape.
class SphereCollider : public Collider
{
	public:
		SphereCollider(Vec3* pos, float r, bool isDefaultRadius = false);
		bool CollidesWith(Collider* other);
		bool CollidesWith(SphereCollider* other);
		float GetRadius();
		void ApplyScale(Vec3 scale);
		SphereCollider operator*(float m);
	private:
		float radius;
		float defaultRadius;
};

#endif