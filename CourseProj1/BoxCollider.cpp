#include "BoxCollider.h"

BoxCollider::BoxCollider(Vec3 bounds, Vec3* pos) : Collider(COLLIDERTYPE::BOX, pos)
{
	boundaries = bounds;
}

bool BoxCollider::CollidesWith(Collider* other)
{
	switch (other->ColliderType())
	{
		case COLLIDERTYPE::BOX:
		{
			return CollidesWith((BoxCollider*)other);
		}
		default:
		{
			break;
		}
	}
}

bool BoxCollider::CollidesWith(BoxCollider* other)
{
	//Vec3 pos = GetPosition();
	//Vec3 oPos = other->GetPosition();
	//bool a = pos.x <= op
	////return (a.minX <= b.maxX && a.maxX >= b.minX) &&
	//	(a.minY <= b.maxY && a.maxY >= b.minY) &&
	//	(a.minZ <= b.maxZ && a.maxZ >= b.minZ);
	return true;
}