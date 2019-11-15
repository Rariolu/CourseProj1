#include "Collider.h"

Collider::Collider(COLLIDERTYPE type)
{
	colliderType = type;
}

COLLIDERTYPE Collider::ColliderType()
{
	return colliderType;
}