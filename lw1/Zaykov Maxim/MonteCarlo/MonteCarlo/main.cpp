#include "stdafx.h"
#include "MonteCarloPiGenerator.h"

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 3)
		{
			throw logic_error("Usage: MonteCarlo.exe <num of threads> <num of iterations>");
		}
		int numOfThreads = stoi(argv[1]);
		int numOfIterations = stoi(argv[2]);
		MonteCarloPiGenerator generator(numOfIterations, numOfThreads);
		cout << generator.getPi() << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}

