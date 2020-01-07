#ifndef _TEMP_OBJ_LOADER_H
#define _TEMP_OBJ_LOADER_H

#include <glm.hpp>
#include <vector>
#include <string>
#include "Aliases.h"

struct OBJIndex
{
	unsigned int vertexIndex;
	unsigned int uvIndex;
	unsigned int normalIndex;

	bool operator<(const OBJIndex& r) const { return vertexIndex < r.vertexIndex; }
};

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
	vector<OBJIndex> OBJIndices;
	vector<Vec3> vertices;
	vector<Vec2> uvs;
	vector<Vec3> normals;
	bool hasUVs;
	bool hasNormals;

	OBJModel(const string& fileName);

	ObjIndexedModel ToIndexedModel();
private:
	unsigned int FindLastVertexIndex(const vector<OBJIndex*>& indexLookup, const OBJIndex* currentIndex, const ObjIndexedModel& result);
	void CreateOBJFace(const string& line);

	Vec2 ParseOBJVec2(const string& line);
	Vec3 ParseOBJVec3(const string& line);
	OBJIndex ParseOBJIndex(const string& token, bool* hasUVs, bool* hasNormals);
};

#endif