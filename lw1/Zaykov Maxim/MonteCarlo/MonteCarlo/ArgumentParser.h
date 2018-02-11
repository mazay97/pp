#pragma once
class ArgumentParser
{
public:
	bool parse(int argc, char* argv[]);

	int getThreads();
	int getIterations();

private:
	int threads = 0;
	int iterations = 0;
};

