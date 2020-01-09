#ifndef _ABSTRACTSHADER_H
#define _ABSTRACTSHADER_H

#include "glew.h"
#include "Util.h"
#include "Transform.h"
#include "Camera.h"
#include "Logger.h"

class AbstractShader
{
	public:
		//Appends ".vert" and ".frag" to the given filepath and uses these
		//to initialise two openGL shaders. Creates an executable to which
		//the shaders are attached and runs on the GPU.
		AbstractShader(string filename);

		//Detach and delete the openGL shaders from the executable program
		//before deleting the program itself.
		~AbstractShader();

		//Tell openGL to use the executable program associated with this
		//"AbstractShader".
		void Bind();

		//Update the program's "uniform" values using information
		//from the transform and the camera.
		virtual void Update(Transform* transform, Camera* camera) = 0;

	protected:
		//Return the address of the executable program.
		GLuint GetProgram();

	private:

		//Create an openGL shader from the given text and type
		//before returning its address.
		GLuint CreateShader(string text, unsigned int type);

		//The address of the executable program.
		GLuint program;

		//The amount of shaders to be created and used
		//(only a single vertex shader and a single
		//fragment shader are to be used for now).
		static const unsigned int shaderNo = 2;

		//The addresses of the vertex and fragment
		//shaders.
		GLuint shaders[shaderNo];
};

#endif