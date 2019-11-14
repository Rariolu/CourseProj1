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
	std::vector<Vec3> positions;
	std::vector<Vec2> texCoords;
	std::vector<Vec3> normals;
	std::vector<unsigned int> indices;

	void CalcNormals();
};

class OBJModel
{
public:
	std::vector<OBJIndex> OBJIndices;
	std::vector<Vec3> vertices;
	std::vector<Vec2> uvs;
	std::vector<Vec3> normals;
	bool hasUVs;
	bool hasNormals;

	OBJModel(const std::string& fileName);

	ObjIndexedModel ToIndexedModel();
private:
	unsigned int FindLastVertexIndex(const std::vector<OBJIndex*>& indexLookup, const OBJIndex* currentIndex, const ObjIndexedModel& result);
	void CreateOBJFace(const std::string& line);

	Vec2 ParseOBJVec2(const std::string& line);
	Vec3 ParseOBJVec3(const std::string& line);
	OBJIndex ParseOBJIndex(const std::string& token, bool* hasUVs, bool* hasNormals);
};

#endif