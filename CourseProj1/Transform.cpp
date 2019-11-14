#include "Transform.h"

Transform::Transform() : scale(Vec3(1,1,1))
{
	
}

Matrix Transform::GetModel()
{
	Matrix positionMatrix = glm::translate(position);
	Matrix scaleMatrix = glm::scale(scale);
	
	Matrix rotationXMatrix = glm::rotate(rotation.x, Vec3(1, 0, 0));
	Matrix rotationYMatrix = glm::rotate(rotation.y, Vec3(0, 1, 0));
	Matrix rotationZMatrix = glm::rotate(rotation.z, Vec3(0, 0, 1));
	
	Matrix rotationMatrix = rotationXMatrix * rotationYMatrix * rotationZMatrix;

	return positionMatrix * rotationMatrix * scaleMatrix;
}

Vec3* Transform::GetRotation()
{
	return &rotation;
}

Vec3* Transform::GetScale()
{
	return &scale;
}

void Transform::Rotate(AXIS axis, float r)
{
	switch (axis)
	{
		case AXIS::X:
			SetRotation(rotation.x + r, rotation.y, rotation.z);
			break;
		case AXIS::Y:
			SetRotation(rotation.x, rotation.y + r, rotation.z);
			break;
		case AXIS::Z:
			SetRotation(rotation.x, rotation.y, rotation.z + r);
			break;
		default:
			break;
	}
}

//void Transform::SetPosition(float x, float y, float z)
//{
//	SetPosition(Vec3(x, y, z));
//}
//
//void Transform::SetPosition(Vec3 position)
//{
//	this->position = position;
//}

void Transform::SetRotation(float x, float y, float z)
{
	SetRotation(Vec3(x, y, z));
}

void Transform::SetRotation(Vec3 rotation)
{
	this->rotation = rotation;
}

void Transform::SetScale(float x, float y, float z)
{
	SetScale(Vec3(x, y, z));
}

void Transform::SetScale(Vec3 scale)
{
	this->scale = scale;
}