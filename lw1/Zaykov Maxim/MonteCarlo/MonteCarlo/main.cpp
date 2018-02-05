// MonteCarlo.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MonteCarloPiGenerator.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Usage: lw1pp.exe <num of threads> <num of iterations>" << endl;
		return 1;
	}
	try
	{
		int numOfThreads = stoi(argv[1]);
		int numOfIterations = stoi(argv[2]);

		MonteCarloPiGenerator generator(numOfIterations);

		cout << generator.getPi() << endl;
	}
	catch (const std::exception&)
	{
		cout << "Unable parse args" << endl;
	}

	return 0;
}

