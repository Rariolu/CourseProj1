#ifndef _DOUBLEUNIFORMSHADER_H
#define _DOUBLEUNIFORMSHADER_H

#include "AbstractShader.h"

//A child class of "AbstractShader" used to
//store the addresses of  two shader
//"uniforms". This saves having to calculate
//the MVP matrix entirely on the CPU, and instead
//the "Model" and the "ViewProjection" matrices are
//sent to the GPU to be multiplied.
class DoubleUniformShader : public AbstractShader
{
	public:
		DoubleUniformShader(string filename);

		//Calculate the "Model" matrix as well as the "View Projection"
		//matrix before storing them in the "model" and "viewProjection"
		//shader uniforms.
		void Update(Transform* transform, Camera* camera);
	private:
		//The addresses of the "model" and "viewProjection"
		//shader uniforms.
		GLuint uniforms[2];
};

#endif