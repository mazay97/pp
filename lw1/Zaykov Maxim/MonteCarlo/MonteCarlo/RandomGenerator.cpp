#include "stdafx.h"
#include "RandomGenerator.h"

double RandomGenerator::getRandomDouble(const int & min, const int & max)
{
	double randomNum = (double)rand() / RAND_MAX;
	return min + randomNum * (max - min);
}
