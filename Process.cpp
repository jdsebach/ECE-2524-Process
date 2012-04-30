#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "Process.hpp"

Process::Process(const std::vector<char*>& args, bool verbose) :
	verbose(verbose),
	m_name(args[0]),
	m_pid((pid_t)NULL),
	m_writepipe {-1, -1},
	m_readpipe {-1, -1},
	m_pwrite((FILE*)NULL),
	m_pread((FILE*)NULL)
{
	if(pipe(m_writepipe) < 0)
	{
		perror("Unable to make pipe for writing");
		throw std::string("Unable to make pipe for writing");
	}
	if(pipe(m_readpipe) < 0)
	{
		perror("Unable to make pipe for reading");
		throw std::string("Unable to make pipe for reading";
	}
	
	m_pid = fork()

	if(m_pid < 0)
	{
		perror("Process fork failed to work");
		throw std::string("Process fork failed to work");
	}
	else if(m_pid == 0)
	{
		close(PARENT_READ);
		close(PARENT_WRITE);
		dup2(CHILD_READ, 0);
		close(CHILD_READ);
		dup2(CHILD_WRITE, 1);
		close(CHILD_WRITE);
		
		execvp(args[0], const_cast<char**>(&args[0]));
	}
	else
	{
		close(CHILD_READ);
		close(CHILD_WRITE);
		if(verbose)
		{
			std::cerr << "The process '" << m_name << "' forked the PID '" << m_pid << "'" << std::endl;
		}
	}
};

Process::~Process()
{
	if(verbrose)
	{
		std::cerr << "Process '" << m_name << "': Entering ~Process()" << std::endl;
	}
	kill(m_pid, SIGTERM);
	fclose(m_pwrite);i
	int status;
	pid_t pid = waitpid(m_pid, &status, 0);
	if(pid < 0)
	{
		perror("~Process waitpid failed");
	}
	fclose(m_pread);
}

void Process::write(const std::string& string)
{
	fputs(string.c_str(), m_pwrite);
	fflush(m_pwrite);
}

std::string Process::read()
{
	std::string string;
	char* str = NULL;
	size_t numberBytes;
	getline(&str, &numberBytes, m_pread);
	string = str;
	return string;
}

