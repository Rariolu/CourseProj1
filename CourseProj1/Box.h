#ifndef _BOX_H
#define _BOX_H

#include "Aliases.h"

struct Box
{
	public:
		Box(Vec3 pos, Vec3 bounds)
		{
			float xDelta = bounds.x / 2.0f;
			float yDelta = bounds.y / 2.0f;
			float zDelta = bounds.z / 2.0f;
			/*minX vals[3]*/x[0] = pos.x - xDelta;
			/*minY vals[4]*/y[0] = pos.y - yDelta;
			/*minZ vals[5]*/z[0] = pos.z - zDelta;
			/*maxX vals[0]*/x[1] = pos.x + xDelta;
			/*maxY vals[1]*/y[1] = pos.y + yDelta;
			/*maxZ vals[2]*/z[1] = pos.z + zDelta;
			corners[0] = Vec3(x[0], y[0], z[0]);
			corners[1] = Vec3(x[0], y[0], z[1]);
			corners[2] = Vec3(x[0], y[1], z[0]);
			corners[3] = Vec3(x[0], y[1], z[1]);
			corners[4] = Vec3(x[1], y[0], z[0]);
			corners[5] = Vec3(x[1], y[0], z[1]);
			corners[6] = Vec3(x[1], y[1], z[0]);
			corners[7] = Vec3(x[1], y[1], z[1]);
		}
		Box() : Box(Vec3(0, 0, 0), Vec3(1, 1, 1))
		{

		}
		float maxX() { return x[1]; }// return vals[0]; }
		float maxY() { return y[1]; }//return vals[1]; }
		float maxZ() { return z[1]; }//return vals[2]; }
		float minX() { return x[0]; }//return vals[3]; }
		float minY() { return y[0]; }// return vals[4]; }
		float minZ() { return z[0]; }// return vals[5]; }
		float* Xs()	{ return x; }
		float* Ys() { return y; }
		float* Zs() { return z; }
		Vec3* Corners()
		{
			return corners;
		}
		static const int CornerNo = 8;
	private:
		Vec3 corners[CornerNo];
		float x[2];
		float y[2];
		float z[2];
};

#endif