#include "stdafx.h"
#include "ArgumentParser.h"

bool ArgumentParser::parse(int argc, char* argv[])
{
	switch (argc)
	{
	case 3:
		threads = std::stoi(argv[1]);
		iterations = std::stoi(argv[2]);
		if (threads < 1 || iterations < 1)
		{
			throw std::logic_error("<num of threads> and <num of iterations> must be more or equals than 1");
		}
		return true;
	case 2:
		if (std::string(argv[1]) == "--help")
		{
			std::cout << "������������� MonteCarlo.exe <num of threads> <num of iterations>, ��� <num of threads> \n -���������� ������� \n <num of iterations> -���������� �������� ��������� ����� \n" << std::endl;
			return false;
		}
	default:
		throw std::logic_error("Usage: MonteCarlo.exe <num of threads> <num of iterations>  \n       MonteCarlo.exe --help");
		return false;
	}
}

int ArgumentParser::getThreads() const
{
	return threads;
}

int ArgumentParser::getIterations() const
{
	return iterations;
}


