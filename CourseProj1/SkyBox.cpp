#include "SkyBox.h"

SkyBox::SkyBox(string texturePath, string shaderName)
{
	cubeMap = CubeMap(texturePath);
	skyboxShader = (SkyboxShader*)ResourceManager::Instance()->GetShader(shaderName);
	InitialiseCube();
}

SkyBox::~SkyBox()
{

}

void SkyBox::Render()
{
	if (camera)
	{
		// draw skybox as last
		glDepthFunc(GL_LEQUAL);

		skyboxShader->Bind();
		skyboxShader->Update(camera);
		cubeMap.Bind();



		//render mesh
		glBindVertexArray(skyboxVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		glDepthFunc(GL_LESS); // set depth function back to default
	}
}

void SkyBox::SetCamera(Camera* cam)
{
	camera = cam;
}

void SkyBox::InitialiseCube()
{
	unsigned int skyboxVAO;
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}