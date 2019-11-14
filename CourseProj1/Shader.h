#ifndef _SHADER_H
#define _SHADER_H

#include "glew.h"
#include "Util.h"
#include "Transform.h"
#include "Camera.h"

class Shader
{
	public:
		Shader(string filename);
		~Shader();
		void Bind();
		GLuint CreateShader(string text, unsigned int type);
		void Update(Transform* transform, Camera* camera);
	private:
		static const unsigned int shaderNo = 2;
		GLuint program;
		GLuint shaders[shaderNo];
		//GLuint uniforms[1];
		GLuint uniforms[2];
};

#endif