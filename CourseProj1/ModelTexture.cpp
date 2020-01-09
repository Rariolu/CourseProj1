#include "ModelTexture.h"

ModelTexture::ModelTexture(string filename)
{
	int width;
	int height;
	int componentNumber;

	//Load image data from the given file name and store in "imageData".
	unsigned char* imageData = stbi_load(filename.c_str(), &width, &height, &componentNumber, 4);
	
	if (!imageData)
	{
		Log("Image from file \"" + filename + "\" failed to load.");
	}

	glGenTextures(1, &textureHandler);
	glBindTexture(GL_TEXTURE_2D, textureHandler);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	stbi_image_free(imageData);
}

ModelTexture::~ModelTexture()
{
	glDeleteTextures(1, &textureHandler);
}

void ModelTexture::Bind()
{
	assert(thisUnit >= 0 && thisUnit <= 31);

	glActiveTexture(GL_TEXTURE0 + thisUnit);
	glBindTexture(GL_TEXTURE_2D, textureHandler);
}