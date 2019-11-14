#include "ObjLoad.h"

bool LoadOBJ(string filename, Mesh* mesh)
{
	bool* uvsFound = new bool(false);
	bool* normalsFound = new bool(false);

	vector<MeshIndex>* indices = new vector<MeshIndex>();
	vector<Vec3>* vertices = new vector<Vec3>();
	vector<Vec3>* normals = new vector<Vec3>();
	vector<Vec2>* uvs = new vector<Vec2>();
	if (!GetOBJVectors(filename, indices, vertices, normals, uvs, uvsFound, normalsFound))
	{
		std::cout << "Unable to load :\"" << filename << "\"." << std::endl;
		return false;
	}

	IndexedModel* indexedModel = GenerateIndexedModel(indices, vertices, normals, uvs, *normalsFound, *uvsFound);
	return Mesh::LoadModel(indexedModel);
}

bool GetOBJVectors(string filename, vector<MeshIndex>* meshIndices, vector<Vec3>* vertices, vector<Vec3>* normals, vector<Vec2>* uvs, bool* uvsFound, bool* normalsFound)
{
	InputFileStream file;
	file.open(filename.c_str());
	string currentLine;
	if (file.is_open())
	{
		while (file.good())
		{
			std::getline(file, currentLine);
			unsigned int length = currentLine.length();
			if (length < 2)
			{
				continue;
			}
			const char* lineCharArray = currentLine.c_str();
			switch (lineCharArray[0])
			{
				case 'v':
				{
					switch (lineCharArray[1])
					{
						case 't':
						{
							uvs->push_back(ParseOBJVec2(currentLine));
						}
						case 'n':
						{
							normals->push_back(ParseOBJVec3(currentLine));
						}
						case ' ' : case '\t':
						{
							vertices->push_back(ParseOBJVec3(currentLine));
						}
					}
					break;
				}
				case 'f':
				{
					CreateOBJFace(currentLine,meshIndices,uvsFound,normalsFound);
					break;
				}
			}
		}
		return true;
	}
	return false;
}

bool CompareMeshIndices(MeshIndex* a, MeshIndex* b)
{
	return a->vertexIndex < b->vertexIndex;
}

void CreateOBJFace(string line, vector<MeshIndex>* meshIndices, bool* uvsFound, bool* normalsFound)
{
	vector<string> tokens = SplitString(line, ' ');
	meshIndices->push_back(ParseMeshIndex(tokens[1], uvsFound, normalsFound));
	meshIndices->push_back(ParseMeshIndex(tokens[2], uvsFound, normalsFound));
	meshIndices->push_back(ParseMeshIndex(tokens[3], uvsFound, normalsFound));
	if (tokens.size() > 4)
	{
		meshIndices->push_back(ParseMeshIndex(tokens[1], uvsFound, normalsFound));
		meshIndices->push_back(ParseMeshIndex(tokens[3], uvsFound, normalsFound));
		meshIndices->push_back(ParseMeshIndex(tokens[4], uvsFound, normalsFound));
	}
}

unsigned int FindNextCharacter(unsigned int start, const char* str, unsigned int length, char token)
{
	unsigned int result = start;
	while (result < length)
	{
		result++;
		if (str[result] == token)
		{
			break;
		}
	}
	return result;
}

unsigned int FindLastVertexInex(vector<MeshIndex*> indexLookup, vector<Vec3>* vertices, vector<Vec3>* normals, vector<Vec2>* uvs, MeshIndex* currentIndex, IndexedModel* result, bool normalsFound,bool uvsFound)
{
	unsigned int start = 0;
	unsigned int end = indexLookup.size();
	unsigned int current = ((end - start) / 2) + start;
	unsigned int previous = start;

	while (current != previous)
	{
		MeshIndex* testIndex = indexLookup[current];
		if (testIndex->vertexIndex == currentIndex->vertexIndex)
		{
			unsigned int countStart = current;

			for (unsigned int i = 0; i < current; i++)
			{
				MeshIndex* possibleIndex = indexLookup[current - i];
				if (possibleIndex == currentIndex)
				{
					continue;
				}
				if (possibleIndex->vertexIndex != currentIndex->vertexIndex)
				{
					break;
				}
				countStart--;
			}

			for (unsigned int i = countStart; i < indexLookup.size() - countStart; i++)
			{
				MeshIndex* possibleIndex = indexLookup[current + i];
				bool uv = (!uvsFound || possibleIndex->uvIndex == currentIndex->uvIndex);
				bool normal = (!normalsFound || possibleIndex->normalIndex == currentIndex->normalIndex);
				if (possibleIndex == currentIndex)
				{
					continue;
				}
				if (possibleIndex->vertexIndex != currentIndex->vertexIndex)
				{
					break;
				}
				else if (uv && normal)
				{
					Vec3 currentPosition = vertices->at(currentIndex->vertexIndex);
					Vec3 currentNormal = normalsFound ? normals->at(currentIndex->normalIndex) : Vec3(0,0,0);
					Vec2 currentUV = uvsFound ? uvs->at(currentIndex->uvIndex) : Vec2(0,0);

					for (unsigned int j = 0; j < result->positions.size(); j++)
					{
						bool isCurrentNormal = (!normalsFound || currentNormal == result->normals[j]);
						bool isCurrentUV = (!uvsFound || currentUV == result->uvCoordinates[j]);
						if (currentPosition == result->positions[j])
						{
							return j;
						}
					}
				}
			}

			return -1;
		}
		else
		{
			if (testIndex->vertexIndex < currentIndex->vertexIndex)
			{
				start = current;
			}
			else
			{
				end = current;
			}
		}
		previous = current;
		current = ((end - start) / 2) + start;
	}

	return -1;
}

IndexedModel* GenerateIndexedModel(vector<MeshIndex>* indices, vector<Vec3>* vertices, vector<Vec3>* normals, vector<Vec2>* uvs, bool normalsFound, bool uvsFound)
{
	IndexedModel* result = new IndexedModel();
	IndexedModel* normalModel = new IndexedModel();

	unsigned int indexNo = indices->size();

	vector<MeshIndex*>  indexLookup;
	for (unsigned int i = 0; i < indexNo; i++)
	{
		indexLookup.push_back(&indices->at(i));
	}

	std::sort(indexLookup.begin(), indexLookup.end(), CompareMeshIndices);

	map<MeshIndex, unsigned int> normalModelIndexMap;
	map<unsigned int, unsigned int> indexMap;
	for (unsigned int i = 0; i < indexNo; i++)
	{
		MeshIndex* currentIndex = &indices->at(i);

		Vec3 currentPosition = vertices->at(currentIndex->vertexIndex);
		Vec3 currentNormal = normalsFound ? normals->at(currentIndex->normalIndex) : Vec3(0, 0, 0);
		Vec2 currentUV = uvsFound ? uvs->at(currentIndex->uvIndex) : Vec2(0, 0);

		unsigned int normalModelIndex;
		unsigned int resultModelIndex;
		map<MeshIndex, unsigned int>::iterator it = normalModelIndexMap.find(*currentIndex);
		if (it == normalModelIndexMap.end())
		{
			normalModelIndex = normalModel->positions.size();

			normalModelIndexMap.insert(pair<MeshIndex, unsigned int>(*currentIndex, normalModelIndex));
			normalModel->positions.push_back(currentPosition);
			normalModel->normals.push_back(currentNormal);
			normalModel->uvCoordinates.push_back(currentUV);
		}
		else
		{
			normalModelIndex = it->second;
		}

		unsigned int previousVertexLocation = FindLastVertexInex(indexLookup,vertices,normals,uvs, currentIndex, result,normalsFound,uvsFound);
		if (previousVertexLocation == (unsigned int)-1)
		{
			resultModelIndex = result->positions.size();

			result->positions.push_back(currentPosition);
			result->normals.push_back(currentNormal);
			result->uvCoordinates.push_back(currentUV);
		}
		else
		{
			resultModelIndex = previousVertexLocation;
		}

		normalModel->indices.push_back(normalModelIndex);
		result->indices.push_back(resultModelIndex);
		indexMap.insert(pair<unsigned int, unsigned int>(resultModelIndex, normalModelIndex));
	}
	if (!normalsFound)
	{
		normalModel->CalculateNormals();

		for (unsigned int i = 0; i < result->positions.size(); i++)
		{
			result->normals[i] = normalModel->normals[indexMap[i]];
		}
	}
	return result;
}

float ParseOBJFloatValue(string token, unsigned int start, unsigned int end)
{
	return (float)atof(token.substr(start, end - start).c_str());
}

MeshIndex ParseMeshIndex(string token, bool* uvsFound, bool* normalsFound)
{
	unsigned int length = token.length();
	const char* tokenString = token.c_str();

	unsigned int startIndex = 0;
	unsigned int endIndex = FindNextCharacter(startIndex, tokenString, length, '/');

	MeshIndex result;
	result.vertexIndex = ParseMeshIndexValue(token, startIndex, endIndex);
	result.uvIndex = 0;
	result.normalIndex = 0;

	if (endIndex >= length)
	{
		return result;
	}

	startIndex = endIndex + 1;
	endIndex = FindNextCharacter(startIndex, tokenString, length, '/');

	result.uvIndex = ParseMeshIndexValue(token, startIndex, endIndex);
	(*uvsFound) = true;

	if (endIndex >= length)
	{
		return result;
	}

	startIndex = endIndex + 1;
	endIndex = FindNextCharacter(startIndex, tokenString, length, '/');

	result.normalIndex = ParseMeshIndexValue(token, startIndex, endIndex);
	(*normalsFound) = true;

	return result;
}

unsigned int ParseMeshIndexValue(string token, unsigned int start, unsigned int end)
{
	return atoi(token.substr(start, end - start).c_str()) - 1;
}

vector<float> ParseOBJVector(string line, int size, int startIndex)
{
	unsigned int length = line.length();
	const char* tokenString = line.c_str();
	while (startIndex < length)
	{
		if (tokenString[startIndex] != ' ')
		{
			break;
		}
		startIndex++;
	}
	vector<float> values;
	unsigned int endIndex;
	for (int i = 0; i < size; i++)
	{
		endIndex = FindNextCharacter(startIndex, tokenString, length, ' ');
		float value = startIndex < endIndex ? ParseOBJFloatValue(line, startIndex, endIndex) : 0.0f;
		values.push_back(value);
		startIndex = endIndex + 1;
	}
	return values;
}

Vec2 ParseOBJVec2(string line)
{
	vector<float> values = ParseOBJVector(line, 2, 3);
	Vec2 v(values[0], values[1]);
	return v;
}

Vec3 ParseOBJVec3(string line)
{
	vector<float> values = ParseOBJVector(line, 3, 2);
	Vec3 v(values[0], values[1], values[2]);
	return v;
}

vector<string> SplitString(string str, char delimiter)
{
	vector<string> elements;
	const char* cstr = str.c_str();
	unsigned int length = str.length();
	unsigned int start = 0;
	unsigned int end = 0;
	while (end <= length)
	{
		while (end <= length)
		{
			if (cstr[end] == delimiter)
			{
				break;
			}
			end++;
		}
		elements.push_back(str.substr(start, end - start));
		start = end + 1;
		end = start;
	}
	return elements;
}