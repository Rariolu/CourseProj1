#include "AbstractShader.h"

AbstractShader::AbstractShader(string filename)
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

	glLinkProgram(program);
	glValidateProgram(program);
}

AbstractShader::~AbstractShader()
{
	for (unsigned int i = 0; i < shaderNo; i++)
	{
		glDetachShader(program, shaders[i]);
		glDeleteShader(shaders[i]);
	}
	glDeleteProgram(program);
}

void AbstractShader::Bind()
{
	glUseProgram(program);
}

GLuint AbstractShader::GetProgram()
{
	return program;
}

GLuint AbstractShader::CreateShader(string text, unsigned int type)
{
	GLuint shader = glCreateShader(type);

	if (!shader)
	{
		Log("Shader failed to be created.");
	}

	const GLchar* stringsource[] = { text.c_str() };
	GLint lengths[] = { text.length() };

	glShaderSource(shader, 1, stringsource, lengths);
	glCompileShader(shader);

	return shader;
}