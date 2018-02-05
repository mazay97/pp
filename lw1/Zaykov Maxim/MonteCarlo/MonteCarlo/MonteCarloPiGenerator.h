#pragma once

#include "RandomGenerator.h"

class MonteCarloPiGenerator
{
private:
	double numOfInsideDots = 0;
	int counter = 0;
	int iterationsNumber = 0;

	bool isDotInCircle(double x, double y);

	void countPI();

public:

	MonteCarloPiGenerator(int num);

	double getPi();
};

