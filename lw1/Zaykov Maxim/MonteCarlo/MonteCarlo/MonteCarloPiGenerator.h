#pragma once

#include "RandomGenerator.h"

struct ThreadData
{
	ThreadData(const size_t & iterations, const size_t & points, const size_t & iterationsNum) :
		countIterations(iterations), 
		countPointsInCircle(points),
		iterationsNumber(iterationsNum)
	{};
	size_t countPointsInCircle;
	size_t countIterations;
	const size_t iterationsNumber;
};

class MonteCarloPiGenerator
{
private:
	int iterationsNumber = 0;
	int threadsNumber = 0;
	int pointsInside = 0;

	static bool isDotInCircle(const double & x, const double & y);

public:

	MonteCarloPiGenerator(int numOfIterations, const int numOfThreads);

	static DWORD WINAPI countPI(LPVOID lpParameter);

	double getPi();
};

