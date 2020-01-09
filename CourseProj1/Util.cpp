#include "Util.h"

string LoadText(string filename)
{
	InputFileStream file;
	file.open(filename.c_str());

	string output;
	string currentLine;
	if (file.is_open())
	{
		while (file.good())
		{
			std::getline(file, currentLine);
			output += currentLine + "\n";
		}
	}
	return output;
}

int RandomNumber(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

Matrix RemoveTranslation(Matrix mat)
{
	Mat3 m3 = Mat3(mat);
	return Matrix(m3);
	//TODO: Replace with more efficient method
}

float SquareValue(float value)
{
	return value * value;
}