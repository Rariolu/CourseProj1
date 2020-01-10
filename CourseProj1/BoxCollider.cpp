#include "BoxCollider.h"

BoxCollider::BoxCollider(Vec3 bounds, Vec3* pos) : BoxCollider(new Box(bounds),pos)
{
	
}

BoxCollider::BoxCollider(Box* box, Vec3* pos) : Collider(COLLIDERTYPE::BOX, pos)
{
	boundBox = box;
	boundBox->SetPosition(pos);
}

Box* BoxCollider::BoundBox()
{
	return boundBox;
}

bool BoxCollider::CollidesWith(Collider* other)
{
	//Call the relevant collision function if
	//the collider type of the other collider
	//is a box collider or sphere collider.
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

	//For each axis, determine if there is an overlap between the min and max values of the two boxes.
	bool x = boundBox->minX() <= otherBound->maxX() && boundBox->maxX() >= otherBound->minX();
	bool y = boundBox->minY() <= otherBound->maxY() && boundBox->maxY() >= otherBound->minY();
	bool z = boundBox->minZ() <= otherBound->maxZ() && boundBox->maxZ() >= otherBound->minZ();
	
	//Collision has occurred if overlap has occurred in all three axes.
	return x && y && z;
}

bool BoxCollider::CollidesWith(SphereCollider* other)
{
	Vec3 oPos = other->GetPosition();

	//Determine the position of the bounding box that is closest to
	//the centre of the sphere.
	float x = max(boundBox->minX(), min(oPos.x, boundBox->maxX()));
	float y = max(boundBox->minY(), min(oPos.y, boundBox->maxY()));
	float z = max(boundBox->minZ(), min(oPos.z, boundBox->maxZ()));

	//Determine the square distance between the sphere's centre and the point.
	float d2 = SquareValue(x - oPos.x) + SquareValue(y - oPos.y) + SquareValue(z - oPos.z);
	//Get the sphere's radius and square it.
	float r2 = SquareValue(other->GetRadius());

	//Collision has occurred if the square distance is less than
	//or equal to the square radius.
	return d2 <= r2;
}