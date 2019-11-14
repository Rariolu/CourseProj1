#ifndef _MESH_H
#define _MESH_H

#include "glm.hpp"
#include "glew.h"

#include "IndexedModel.h"
#include "Temp_obj_loader.h"
#include "Vertex.h"

class Mesh
{
	public:
		~Mesh();
		static Mesh* LoadModel(IndexedModel* model);
		static Mesh* LoadModel(ObjIndexedModel* model);
		void Render();
	private:
		Mesh();
		void InitialiseModel(IndexedModel* model);
		void InitialiseModel(ObjIndexedModel* model);
		const static short bufferCount = 4;
		unsigned int drawCount;
		GLuint vertexArrayObject;
		GLuint vertexArrayBuffers[bufferCount];
};

#endif