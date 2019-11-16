#ifndef _TRIPLEUNIFORMSHADER_H
#define _TRIPLEUNIFORMSHADER_H

#include "AbstractShader.h"

//A child class of "AbstractShader" used to
//store the addresses of four shader
//"uniforms". This saves having to calculate
//the "Model" matrix on the CPU as the individual
//position, rotation, and scale vectors are passed
//to the GPU to be factored into the "model" matrix
//before being multiplied by the "View Projection"
//matrix.
class QuadrupleUniformShader : public AbstractShader
{
	public:
		QuadrupleUniformShader(string filename);
		void Update(Transform* transform, Camera* camera);
	private:
		GLuint uniforms[4];
};

#endif