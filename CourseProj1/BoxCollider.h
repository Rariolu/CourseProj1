#ifndef _BOXCOLLIDER_H
#define _BOXCOLLIDER_H

#include "Collider.h"
#include "Box.h"
#include "SphereCollider.h"

class BoxCollider : public Collider
{
	public:
		BoxCollider(Vec3 bounds, Vec3* pos);
		BoxCollider(Box* box, Vec3* pos);
		bool CollidesWith(Collider* other);
		Box* BoundBox();
	private:
		bool CollidesWith(BoxCollider* other);
		bool CollidesWith(SphereCollider* other);
		Box* boundBox;
};

#endif