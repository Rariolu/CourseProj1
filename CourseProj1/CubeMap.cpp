#include "CubeMap.h"

CubeMap::CubeMap()
{

}

CubeMap::CubeMap(string filepath) :
	CubeMap(filepath+"posX.png",filepath+"negX.png",filepath+"posY.png",filepath+"negY.png",filepath+"posZ.png",filepath+"negZ.png")
{

}

CubeMap::CubeMap(string posXFile, string negXFile, string posYFile, string negYFile, string posZFile, string negZFile) :
	CubeMap(new string[6]{posXFile,negXFile,posYFile,negYFile,posZFile,negZFile})
{

}

CubeMap::CubeMap(string textures[6])
{
	//https://learnopengl.com/Advanced-OpenGL/Cubemaps

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

	for (int i = 0; i < 6; i++)
	{
		string textureFile = textures[i];
		int width;
		int height;
		int nrChannels;
		
		//Load the requested texture file into "data".
		unsigned char* data = stbi_load(textureFile.c_str(), &width, &height, &nrChannels, 0);
		
		if (data)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		else
		{
			std::cout << textureFile << ": failed to load" << std::endl;
		}

		//"Free" the image data now that it's no longer needed.
		stbi_image_free(data);
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

CubeMap::~CubeMap()
{
	glDeleteTextures(1, &texture);
}

void CubeMap::Bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
}