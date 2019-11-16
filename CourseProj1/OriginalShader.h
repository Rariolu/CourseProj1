#ifndef _ORIGINALSHADER_H
#define _ORIGINALSHADER_H

#include "AbstractShader.h"

//A child class of "AbstractShader" used to
//store only the address of a single shader
//"uniform" and therefore have to perform
//the complete MVP calculation on the CPU.
class OriginalShader : public AbstractShader
{
	public:
		OriginalShader(string filename);

		//Calculate the "ModelViewProjection" matrix and store
		//it in the shader's "mvp" uniform variable.
		void Update(Transform* transform, Camera* camera);
	private:
		//The address of the "mvp" shader uniform.
		GLuint uniform;
};

#endif