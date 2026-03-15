#pragma once

#include <string>
#include <iostream>

struct ProgramConfig {
	int space{ 0 };
	int radius{ 0 };
	int count_points{ 0 };
	bool interactive{ false };
	bool verbose{ false };

	void Print() const{
		std::cout << "Configuration: \n"
	    << " space = " << space << "\n"
		<< " radius = " << radius << "\n"
		<< " count points = " << count_points << "\n"
	    << " interactive: " << (interactive ? "yes" : "no") << "\n"
		<< " verbose: " << (verbose ? "yes" : "no") << std::endl;
	}

};

ProgramConfig parse_command_line(int argc, char* argv[]);
void PrintUsage(const char* prog_name);
