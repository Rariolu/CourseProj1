#include "Shader.h"

Shader::Shader(string filename)
{
	program = glCreateProgram();
	
	string vertexshader = LoadText(filename + ".vert");
	shaders[0] = CreateShader(vertexshader, GL_VERTEX_SHADER);
	
	string fragmentshader = LoadText(filename + ".frag");
	shaders[1] = CreateShader(fragmentshader, GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < shaderNo; i++)
	{
		glAttachShader(program, shaders[i]);
	}

	glBindAttribLocation(program, 0, "position");
	glBindAttribLocation(program, 1, "texCoord");

	glLinkProgram(program);

	glValidateProgram(program);

	//uniforms[0] = glGetUniformLocation(program, "transform");
	uniforms[0] = glGetUniformLocation(program, "model");
	uniforms[1] = glGetUniformLocation(program, "viewProjection");
}

Shader::~Shader()
{
	for (unsigned int i = 0; i < shaderNo; i++)
	{
		glDetachShader(program, shaders[i]);
		glDeleteShader(shaders[i]);
	}
	glDeleteProgram(program);
}

void Shader::Bind()
{
	glUseProgram(program);
}

GLuint Shader::CreateShader(string text, unsigned int type)
{
	GLuint shader = glCreateShader(type);

	if (!shader)
	{
		//error message
	}

	const GLchar* stringsource[] = { text.c_str() };
	GLint lengths[] = { text.length() };

	glShaderSource(shader, 1, stringsource, lengths);
	glCompileShader(shader);

	return shader;
}

void Shader::Update(Transform* transform, Camera* camera)
{
	Matrix mvp = camera->GetViewProjection() * transform->GetModel();
	float n = mvp[0][0];
	//glUniformMatrix4fv(uniforms[0], 1, GLU_FALSE, &mvp[0][0]);
	glUniformMatrix4fv(uniforms[0], 1, GLU_FALSE, &transform->GetModel()[0][0]);
	glUniformMatrix4fv(uniforms[1], 1, GLU_FALSE, &camera->GetViewProjection()[0][0]);
}