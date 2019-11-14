#include "MutablePoint.h"

Vec3* MutablePoint::GetPosition()
{
	return &position;
}

void MutablePoint::SetPosition(float x, float y, float z)
{
	SetPosition(Vec3(x, y, z));
}

void MutablePoint::SetPosition(Vec3 position)
{
	this->position = position;
}

void MutablePoint::Translate(AXIS axis, float t)
{
	switch (axis)
	{
		case AXIS::X:
			SetPosition(position.x + t, position.y, position.z);
			break;
		case AXIS::Y:
			SetPosition(position.x, position.y + t, position.z);
			break;
		case AXIS::Z:
			SetPosition(position.x, position.y, position.z + t);
			break;
		default:
			break;
	}
}