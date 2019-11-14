#ifndef _OBJLOAD_H
#define _OBJLOAD_H

#include <algorithm>
#include <iostream>
#include "Mesh.h"
#include "IndexedModel.h"

struct MeshIndex
{
	unsigned int vertexIndex;
	unsigned int uvIndex;
	unsigned int normalIndex;
	bool operator<(const MeshIndex& other) const
	{
		return vertexIndex < other.vertexIndex;
	}
};

bool LoadOBJ(string filename, Mesh* mesh);
bool GetOBJVectors(string filename, vector<MeshIndex>* meshIndices, vector<Vec3>* vertices, vector<Vec3>* normals, vector<Vec2>* uvs, bool* uvsFound, bool* normalsFound);

bool CompareMeshIndices(MeshIndex* a, MeshIndex* b);
void CreateOBJFace(string line, vector<MeshIndex>* meshIndices, bool* uvsFound, bool* normalsFound);
unsigned int FindNextCharacter(unsigned int start, const char* str, unsigned int length, char token);
unsigned int FindLastVertexInex(vector<MeshIndex*> indexLookup, vector<Vec3>* vertices, vector<Vec3>* normals, vector<Vec2>* uvs, MeshIndex* currentIndex, IndexedModel* result, bool normalsFound, bool uvsFound);
IndexedModel* GenerateIndexedModel(vector<MeshIndex>* indices, vector<Vec3>* vertices, vector<Vec3>* normals, vector<Vec2>* uvs, bool normalsFound, bool uvsFound);
float ParseOBJFloatValue(string token, unsigned int start, unsigned int end);
MeshIndex ParseMeshIndex(string token, bool* uvsFound, bool* normalsFound);
unsigned int ParseMeshIndexValue(string token, unsigned int start, unsigned int end);
vector<float> ParseOBJVector(string line, int size, int startIndex);
Vec2 ParseOBJVec2(string line);
Vec3 ParseOBJVec3(string line);
vector<string> SplitString(string str, char delimiter);



#endif