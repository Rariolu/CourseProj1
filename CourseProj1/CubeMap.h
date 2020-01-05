#ifndef _CUBEMAP_H
#define _CUBEMAP_H

#include "glew.h"
#include <iostream>
#include <cstring>
#include "Aliases.h"
#include "stb_image.h"

class CubeMap
{
	public:
		CubeMap(string filepath);
		CubeMap(string posXFile, string negXFile, string posYFile, string negYFile, string posZFile, string negZFile);
		CubeMap(string textures[6]);
		~CubeMap();
	private:
		GLuint texture;
};

#endif