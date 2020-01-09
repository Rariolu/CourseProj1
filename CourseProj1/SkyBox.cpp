#include "SkyBox.h"

SkyBox::SkyBox(string texturePath, string shaderName)
{
	cubeMap = CubeMap(texturePath);
	skyboxShader = (SkyboxShader*)ResourceManager::Instance()->GetShader(shaderName);
	InitialiseCube();
}

SkyBox::~SkyBox()
{
	glDeleteVertexArrays(1, &skyboxVAO);
	glDeleteBuffers(1, &skyboxVBO);
}

void SkyBox::Render()
{
	if (camera)
	{

		glDepthMask(GL_FALSE);
		
		glDepthFunc(GL_LEQUAL);

		skyboxShader->Bind();
		skyboxShader->Update(camera);
		
		cubeMap.Bind();

		//Bind the skybox vertices.
		glBindVertexArray(skyboxVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		glDepthFunc(GL_LESS);
		//Set depth function back to default

		glDepthMask(GL_TRUE);
	}
}

void SkyBox::SetCamera(Camera* cam)
{
	camera = cam;
}

void SkyBox::InitialiseCube()
{
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}