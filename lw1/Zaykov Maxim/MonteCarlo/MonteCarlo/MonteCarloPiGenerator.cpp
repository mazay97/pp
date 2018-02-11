#include "stdafx.h"
#include "MonteCarloPiGenerator.h"

MonteCarloPiGenerator::MonteCarloPiGenerator(const int numOfIterations, const int numOfThreads)
{
	iterationsNumber = numOfIterations;
	threadsNumber = numOfThreads;
	if (threadsNumber == 1)
	{
		type = SINGLETHREAD;
	}
	else
	{
		type = MULTITHREAD;
	}
}

bool MonteCarloPiGenerator::isDotInCircle(const double & x, const double & y)
{
	return x * x + y * y <= 1;
}

double MonteCarloPiGenerator::multithreadedCalculation()
{
	std::vector<HANDLE> threads;
	ThreadData data(0, 0, iterationsNumber);

	for (size_t i = 0; i < threadsNumber; ++i)
	{
		threads.push_back(CreateThread(NULL, 0, countPI, &data, 0, 0));
	}

	WaitForMultipleObjects(threads.size(), threads.data(), true, INFINITE);

	for (auto &thread : threads)
	{
		CloseHandle(thread);
	}

	return 4 * double(data.countPointsInCircle) / double(iterationsNumber);
}

double MonteCarloPiGenerator::singlethreadedCalculation()
{
	ThreadData data(0, 0, iterationsNumber);

	countPI(&data);

	return 4 * double(data.countPointsInCircle) / double(iterationsNumber);
}

DWORD WINAPI MonteCarloPiGenerator::countPI(LPVOID lpParameter)
{
	ThreadData * data = ((ThreadData*)lpParameter);
	RandomGenerator generator;
	double x, y;

	for (size_t i = 0; i < data->iterationsNumber; ++i)
	{
		x = generator.getRandomDouble(-1, 1);
		y = generator.getRandomDouble(-1, 1);

		if (data->iterationsNumber <= data->countIterations)
		{
			break;
		}

		if (isDotInCircle(x, y))
		{
			InterlockedIncrement(&data->countPointsInCircle);
		}
		InterlockedIncrement(&data->countIterations);
	}
	return 0;
}

double MonteCarloPiGenerator::getPi()
{
	if (type == SINGLETHREAD)
	{
		return singlethreadedCalculation();
	}
	else
	{
		return multithreadedCalculation();
	}
}
