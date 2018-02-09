#include "stdafx.h"
#include "RandomGenerator.h"

double RandomGenerator::getRandomDouble(const double & min, const double & max)
{
	double randomNum = (double)rand() / RAND_MAX;
	return min + randomNum * (max - min);
}
