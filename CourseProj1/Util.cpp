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