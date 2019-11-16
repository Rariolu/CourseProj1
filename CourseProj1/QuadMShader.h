#ifndef _QUADMSHADER_H
#define _QUADMSHADER_H

#include "AbstractShader.h"

class QuadMShader : public AbstractShader
{
	public:
		QuadMShader(string filename);
		void Update(Transform* transform, Camera* camera);
	private:
		GLuint uniforms[4];
};

#endif