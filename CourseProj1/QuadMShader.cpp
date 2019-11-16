#include "QuadMShader.h"

QuadMShader::QuadMShader(string filename) : AbstractShader(filename)
{
	GLuint program = GetProgram();
	glBindAttribLocation(program, 0, "position");
	glBindAttribLocation(program, 1, "texCoord");

	uniforms[0] = glGetUniformLocation(program, "positionMatrix");
	uniforms[1] = glGetUniformLocation(program, "rotationMatrix");
	uniforms[2] = glGetUniformLocation(program, "scaleMatrix");
	uniforms[3] = glGetUniformLocation(program, "viewProjection");
}

void QuadMShader::Update(Transform* transform, Camera* camera)
{
	Matrix positionMatrix = glm::translate(*transform->GetPosition());
	Vec3 r = *transform->GetRotation();
	Matrix rotX = glm::rotate(r.x, Vec3(1, 0, 0));
	Matrix rotY = glm::rotate(r.y, Vec3(0, 1, 0));
	Matrix rotZ = glm::rotate(r.z, Vec3(0, 0, 1));
	Matrix rotationMatrix = rotX * rotY * rotZ;
	Matrix scaleMatrix = glm::scale(*transform->GetScale());
	glUniformMatrix4fv(uniforms[0], 1, GLU_FALSE, &positionMatrix[0][0]);
	glUniformMatrix4fv(uniforms[1], 1, GLU_FALSE, &rotationMatrix[0][0]);
	glUniformMatrix4fv(uniforms[2], 1, GLU_FALSE, &scaleMatrix[0][0]);
	glUniformMatrix4fv(uniforms[3], 1, GLU_FALSE, &camera->GetViewProjection()[0][0]);
}