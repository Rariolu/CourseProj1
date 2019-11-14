#include "QuadrupleUniformShader.h"

QuadrupleUniformShader::QuadrupleUniformShader(string filename) : AbstractShader(filename)
{
	GLuint program = GetProgram();
	glBindAttribLocation(program, 0, "position"); // associate attribute variable with our shader program attribute (in this case attribute vec3 position;)
	glBindAttribLocation(program, 1, "texCoord");
	uniforms[0] = glGetUniformLocation(program, "mPosition");
	uniforms[1] = glGetUniformLocation(program, "rotation");
	uniforms[2] = glGetUniformLocation(program, "scale");
	uniforms[3] = glGetUniformLocation(program, "viewProjection");
}

void QuadrupleUniformShader::Update(Transform* transform, Camera* camera)
{
	Vec3 p = *transform->GetPosition();
	Vec3 r = *transform->GetRotation();
	Vec3 s = *transform->GetScale();
	glUniform3fv(uniforms[0], 1, &p[0]);
	glUniform3fv(uniforms[1], 1, &r[0]);
	glUniform3fv(uniforms[2], 1, &s[0]);
	glUniformMatrix4fv(uniforms[3], 1, GLU_FALSE, &camera->GetViewProjection()[0][0]);
}