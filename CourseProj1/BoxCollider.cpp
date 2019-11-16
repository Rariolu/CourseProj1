#include "BoxCollider.h"

BoxCollider::BoxCollider(Vec3 bounds, Vec3* pos) : BoxCollider(new Box(*pos,bounds),pos)
{
	
}

BoxCollider::BoxCollider(Box* box, Vec3* pos) : Collider(COLLIDERTYPE::BOX, pos)
{
	boundBox = box;
}

Box* BoxCollider::BoundBox()
{
	return boundBox;
}

bool BoxCollider::CollidesWith(Collider* other)
{
	switch (other->ColliderType())
	{
		case COLLIDERTYPE::BOX:
		{
			return CollidesWith((BoxCollider*)other);
		}
		case COLLIDERTYPE::SPHERE:
		{
			return CollidesWith((SphereCollider*)other);
		}
	}
	return false;
}

bool BoxCollider::CollidesWith(BoxCollider* other)
{
	Box* otherBound = other->BoundBox();
	bool x = boundBox->minX() <= otherBound->maxX() && boundBox->maxX() >= otherBound->minX();
	bool y = boundBox->minY() <= otherBound->maxY() && boundBox->maxY() >= otherBound->minY();
	bool z = boundBox->minZ() <= otherBound->maxZ() && boundBox->maxZ() >= otherBound->minZ();
	return x && y && z;
}

bool BoxCollider::CollidesWith(SphereCollider* other)
{
	Vec3* corners = boundBox->Corners();
	Vec3 pos = GetPosition();
	float r2 = SquareValue(other->GetRadius());
	for (unsigned int i = 0; i < Box::CornerNo; i++)
	{
		Vec3 corner = corners[i];
		float d2 = SquareValue(pos.x - corner.x) + SquareValue(pos.y - corner.y) + SquareValue(pos.z - corner.z);
		if (d2 < r2)
		{
			return true;
		}
	}
	return false;
}