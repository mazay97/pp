#include "stdafx.h"
#include "MonteCarloPiGenerator.h"


MonteCarloPiGenerator::MonteCarloPiGenerator(int numOfIterations)
{
	iterationsNumber = numOfIterations;
}

double MonteCarloPiGenerator::getPi()
{
	countPI();
	return 4 * numOfInsideDots / iterationsNumber;
}

void MonteCarloPiGenerator::countPI()
{
	RandomGenerator generator;
	double x, y;
	for (counter; counter <= iterationsNumber; counter++)
	{
		x = generator.getRandomDouble(-1, 1);
		y = generator.getRandomDouble(-1, 1);

		if (isDotInCircle(x, y))
		{
			numOfInsideDots++;
		}
	}
}

bool MonteCarloPiGenerator::isDotInCircle(double x, double y)
{
	return x*x + y*y <= 1;
}
