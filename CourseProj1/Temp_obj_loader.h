#ifndef _TEMP_OBJ_LOADER_H
#define _TEMP_OBJ_LOADER_H

#include <glm.hpp>
#include <vector>
#include <string>
#include "Aliases.h"
#include "Logger.h"

class ObjIndexedModel
{
	public:
		vector<Vec3> positions;
		vector<Vec2> uvCoords;
		vector<Vec3> normals;
		vector<unsigned int> indices;

		void CalcNormals();
};

class OBJModel
{
	public:
		struct OBJIndex
		{
			unsigned int vertexIndex;
			unsigned int uvIndex;
			unsigned int normalIndex;

			bool operator<(const OBJIndex& r) const { return vertexIndex < r.vertexIndex; }
		};
		bool hasNormals;
		bool hasUVs;
		vector<OBJIndex> OBJIndices;
		vector<Vec3> normals;
		vector<Vec2> uvs;
		vector<Vec3> vertices;
		
		OBJModel(const string fileName);

		ObjIndexedModel ToIndexedModel();
	private:

		void CreateOBJFace(const string line);

		unsigned int FindLastVertexIndex(const vector<OBJIndex*>& indexLookup, const OBJIndex* currentIndex, const ObjIndexedModel& result);
		
		OBJIndex ParseOBJIndex(const string& token, bool* hasUVs, bool* hasNormals);
		Vec2 ParseOBJVec2(const string& line);
		Vec3 ParseOBJVec3(const string& line);
};

#endif