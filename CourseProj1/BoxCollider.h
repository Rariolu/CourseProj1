#ifndef _BOXCOLLIDER_H
#define _BOXCOLLIDER_H

#include "Collider.h"

class BoxCollider : public Collider
{
	public:
		BoxCollider(Vec3 bounds, Vec3* pos);
		bool CollidesWith(Collider* other);
	private:
		bool CollidesWith(BoxCollider* other);
		Vec3 boundaries;
};

#endif