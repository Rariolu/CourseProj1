#include "SphereCollider.h"

SphereCollider::SphereCollider(Vec3* pos, float r) : Collider(COLLIDERTYPE::SPHERE)
{
	radius = r;
	position = pos;
}

bool SphereCollider::CollidesWith(Collider* other)
{
	switch (other->ColliderType())
	{
		case COLLIDERTYPE::SPHERE:
		{
			return CollidesWith((SphereCollider*)other);
		}
		default:
		{
			break;
		}
	}
	return false;
}

bool SphereCollider::CollidesWith(SphereCollider* other)
{
	Vec3 otherPos = other->GetPosition();
	float rSumSquared = SquareValue(other->GetRadius() + other->GetRadius());
	float dSquared = SquareValue(position->x - otherPos.x) + SquareValue(position->y - otherPos.y) + SquareValue(position->z - otherPos.z);
	return dSquared <= rSumSquared;
}

Vec3 SphereCollider::GetPosition()
{
	return *position;
}

float SphereCollider::GetRadius()
{
	return radius;
}