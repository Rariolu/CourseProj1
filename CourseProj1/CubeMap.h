#ifndef _CUBEMAP_H
#define _CUBEMAP_H

#include "glew.h"
#include <iostream>
#include <cstring>
#include "Aliases.h"
#include "stb_image.h"
#include "Logger.h"

//A class which represents a cube-map
//texture (a six-sided texture that
//encompasses a cube shape).
class CubeMap
{
	public:
		//Default constructor just to allow
		//default instances to be created.
		CubeMap();

		//Initialise CubeMap using 6 files
		//derived from the given file path
		//(e.g. the positive X texture is the file path plus "posX.png").
		CubeMap(string filepath);

		//Initialise CubeMap using the 6 given file paths.
		CubeMap(string posXFile, string negXFile, string posYFile, string negYFile, string posZFile, string negZFile);
		
		//Initialise CubeMap using the 6 given file paths, assuming
		//that they're in the order of
		//{Positive X file, Negative X file, Positive Y file, Negative Y file, Positive Z file, Negative Z file).
		CubeMap(string textures[6]);
		~CubeMap();

		//Bind the texture to the openGL buffer.
		void Bind();
	private:
		//The ID of the cubemap texture.
		GLuint texture;
};

#endif