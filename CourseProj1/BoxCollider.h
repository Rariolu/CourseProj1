#ifndef _BOXCOLLIDER_H
#define _BOXCOLLIDER_H

#include "Collider.h"
#include "Box.h"
#include "SphereCollider.h"

//A collider that detects collisions within
//its cuboid shape.
class BoxCollider : public Collider
{
	public:
		//Create instance based on the size of the boundaries
		//and a pointer to the location.
		BoxCollider(Vec3 bounds, Vec3* pos);
		BoxCollider(Box* box, Vec3* pos);
		

		void ApplyScale(Vec3 scale);

		//Detect collisions between this BoxCollider
		//and another Collider.
		bool CollidesWith(Collider* other);

		//Detect collisions between this BoxCollider
		//and another BoxCollider.
		bool CollidesWith(BoxCollider* other);
		Box* BoundBox();
	private:
		//Detect collisions between this BoxCollider
		//and a SphereCollider.
		bool CollidesWith(SphereCollider* other);
		
		//A box which represents the boundaries
		//of this collider.
		Box* boundBox;
};

#endif