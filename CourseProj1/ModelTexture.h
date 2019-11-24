#ifndef _MODELTEXTURE_H
#define _MODELTEXTURE_H

#include "stb_image.h"
#include "Aliases.h"
#include "glew.h"

//A class representing a single texture
//that's applied to a mesh. 
class ModelTexture
{
	public:
		ModelTexture(string filename);
		~ModelTexture();
		void Bind();
	private:
		unsigned int thisUnit = 0;
		GLuint textureHandler;
};

#endif