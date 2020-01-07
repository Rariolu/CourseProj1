#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include "Aliases.h"
#include <gtx/transform.hpp>
#include "MutablePoint.h"

struct Transform : public MutablePoint
{
	public:
		Transform();

		//Return the "model" matrix.
		Matrix GetModel();
		Vec3* GetRotation();
		Vec3* GetScale();

		//Rotate the object on a given axis by a given
		//value of degrees.
		void Rotate(AXIS axis, float r);

		//Set the rotation of the object using given
		//x, y, and z values.
		void SetRotation(float x, float y, float z);

		//Set the rotation of the object using a given
		//vector-3.
		void SetRotation(Vec3 rotation);

		//Set the scale of the object using given
		//x, y, and z values
		//(changes size of object to be original
		//size multiplied by these values).
		void SetScale(float x, float y, float z);

		//Set the scale of the object using a given
		//vector-3.
		//(changes size of object to be original
		//size multiplied by these values).
		void SetScale(Vec3 scale);
	private:
		Vec3 rotation;
		Vec3 scale;
};

#endif