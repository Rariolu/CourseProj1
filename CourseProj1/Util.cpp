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

float SquareValue(float value)
{
	return value * value;
}