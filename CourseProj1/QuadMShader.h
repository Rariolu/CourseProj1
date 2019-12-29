#ifndef _QUADMSHADER_H
#define _QUADMSHADER_H

#include "AbstractShader.h"

//A class which provides an interface to a specified
//pair of vertex and fragment shaders.
class QuadMShader : public AbstractShader
{
	public:
		QuadMShader(string filename);

		//Update the shader with the dimensions of the given Transform
		//and the position and orientation of the camera in order to render
		//a specific object.
		void Update(Transform* transform, Camera* camera);
	private:
		GLuint uniforms[4];
};

#endif