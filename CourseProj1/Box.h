#ifndef _BOX_H
#define _BOX_H

#include "Aliases.h"

struct Box
{
	public:
		//Create a box around a hypothetical
		//point by setting the boundaries
		//so that the minimum values are less
		//than zero and the maximum values are greater
		//than zero.
		Box(Vec3 bounds)
		{
			float xDelta = bounds.x / 2.0f;
			float yDelta = bounds.y / 2.0f;
			float zDelta = bounds.z / 2.0f;
			x[0] =	-xDelta;
			y[0] =	-yDelta;
			z[0] =	-zDelta;
			x[1] =	xDelta;
			y[1] =	yDelta;
			z[1] =	zDelta;
			corners[0] = Vec3(x[0], y[0], z[0]);
			corners[1] = Vec3(x[0], y[0], z[1]);
			corners[2] = Vec3(x[0], y[1], z[0]);
			corners[3] = Vec3(x[0], y[1], z[1]);
			corners[4] = Vec3(x[1], y[0], z[0]);
			corners[5] = Vec3(x[1], y[0], z[1]);
			corners[6] = Vec3(x[1], y[1], z[0]);
			corners[7] = Vec3(x[1], y[1], z[1]);
		}
		Box() : Box(Vec3(1, 1, 1))
		{

		}
		void SetPosition(Vec3* pos)
		{
			position = pos;
		}
		Vec3 xyz()
		{
			return Vec3(minX(), minY(), minZ());
		}
		Vec3 xyZ()
		{
			return Vec3(minX(), minY(), maxZ());
		}
		Vec3 xYz()
		{
			return Vec3(minX(), maxY(), minZ());
		}
		Vec3 xYZ()
		{
			return Vec3(minX(), maxY(), maxZ());
		}
		Vec3 Xyz()
		{
			return Vec3(maxX(), minY(), minZ());
		}
		Vec3 XyZ()
		{
			return Vec3(maxX(), minY(), maxZ());
		}
		Vec3 XYz()
		{
			return Vec3(maxX(), maxY(), minZ());
		}
		Vec3 XYZ()
		{
			return Vec3(maxX(), maxY(), maxZ());
		}
		float minX() { return position->x + x[0]; }//return vals[3]; }
		float minY() { return position->y + y[0]; }// return vals[4]; }
		float minZ() { return position->z + z[0]; }// return vals[5]; }
		float maxX() { return position->x + x[1]; }// return vals[0]; }
		float maxY() { return position->y + y[1]; }//return vals[1]; }
		float maxZ() { return position->z + z[1]; }//return vals[2]; }
		Vec3* Corners()
		{
			return new Vec3[CornerNo]
			{
				xyz(),
				xyZ(),
				xYz(),
				xYZ(),
				Xyz(),
				XyZ(),
				XYz(),
				XYZ()
			};
		}
		static const int CornerNo = 8;
	private:
		Vec3* position = new Vec3(0,0,0);
		Vec3 corners[CornerNo];
		float x[2];
		float y[2];
		float z[2];
};

#endif