#include "SphereCollider.h"

SphereCollider::SphereCollider(Vec3* pos, float r) : Collider(COLLIDERTYPE::SPHERE, pos)
{
	radius = r;
}

bool SphereCollider::CollidesWith(Collider* other)
{
	switch (other->ColliderType())
	{
		case COLLIDERTYPE::SPHERE:
		{
			return CollidesWith((SphereCollider*)other);
		}
	}
	return false;
}

bool SphereCollider::CollidesWith(SphereCollider* other)
{
	Vec3 pos = GetPosition();
	Vec3 otherPos = other->GetPosition();
	float rSumSquared = SquareValue(other->GetRadius() + other->GetRadius());
	float dSquared = SquareValue(pos.x - otherPos.x) + SquareValue(pos.y - otherPos.y) + SquareValue(pos.z - otherPos.z);
	return dSquared <= rSumSquared;
}

float SphereCollider::GetRadius()
{
	return radius;
}