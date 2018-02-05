#include "stdafx.h"
#include "RandomGenerator.h"

double RandomGenerator::getRandomDouble(double min, double max)
{
	double randomNum = (double)rand() / RAND_MAX;
	return min + randomNum * (max - min);
}
