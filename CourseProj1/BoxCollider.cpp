#include "BoxCollider.h"

BoxCollider::BoxCollider(Vec3 bounds, Vec3* pos) : BoxCollider(new Box(bounds),pos)
{
	
}

BoxCollider::BoxCollider(Box* box, Vec3* pos) : Collider(COLLIDERTYPE::BOX, pos)
{
	boundBox = box;
	boundBox->SetPosition(pos);
}

void BoxCollider::ApplyScale(Vec3 scale)
{

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
	Vec3 pos = GetPosition();
	Vec3 oPos = other->GetPosition();
	Box* otherBound = other->BoundBox();
	bool x = boundBox->minX() <= otherBound->maxX() && boundBox->maxX() >= otherBound->minX();
	bool y = boundBox->minY() <= otherBound->maxY() && boundBox->maxY() >= otherBound->minY();
	bool z = boundBox->minZ() <= otherBound->maxZ() && boundBox->maxZ() >= otherBound->minZ();
	return x && y && z;
}

bool BoxCollider::CollidesWith(SphereCollider* other)
{
	Vec3 oPos = other->GetPosition();
	float x = max(boundBox->minX(), min(oPos.x, boundBox->maxX()));
	float y = max(boundBox->minY(), min(oPos.y, boundBox->maxY()));
	float z = max(boundBox->minZ(), min(oPos.z, boundBox->maxZ()));

	//Determine the square distance between the sphere's centre and the point.
	float d2 = SquareValue(x - oPos.x) + SquareValue(y - oPos.y) + SquareValue(z - oPos.z);
	//Get the sphere's radius and square it.
	float r2 = SquareValue(other->GetRadius());
	return d2 <= r2;
}