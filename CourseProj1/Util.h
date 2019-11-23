#ifndef _UTIL_H
#define _UTIL_H

#include "Aliases.h"

//Return the text stored in the given file path.
string LoadText(string filename);

//Takes two values, returns the largest of them.
template<typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

//Takes two values, returns the smallest of them.
template<typename T>
T min(T a, T b)
{
	return a < b ? a : b;
}

//Multiply the given value by itself and return the result.
float SquareValue(float value);


#endif