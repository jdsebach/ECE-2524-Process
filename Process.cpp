#include "Process.hpp"

Process::Process(const std::vector<char*>& args, bool verbose)
{
	fork();
	exec();
}

Process::Process(const std::vector<char*>&)
{

}

Process::~Process()
{
	wait();
}
