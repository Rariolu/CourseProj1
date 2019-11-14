#ifndef _ABSTRACTSHADER_H
#define _ABSTRACTSHADER_H

#include "glew.h"
#include "Util.h"
#include "Transform.h"
#include "Camera.h"

class AbstractShader
{
	public:
		AbstractShader(string filename);
		~AbstractShader();
		void Bind();
		virtual void Update(Transform* transform, Camera* camera) = 0;
	protected:
		GLuint GetProgram();
	private:
		GLuint CreateShader(string text, unsigned int type);
		GLuint program;
		static const unsigned int shaderNo = 2;
		GLuint shaders[shaderNo];
};

#endif