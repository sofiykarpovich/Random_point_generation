#pragma once

#include <string>
#include <iostream>

struct ProgramConfig {
	int space { 0 };
	int radius { 0 };
	int count_points { 0 };
	std::string axis_shift {};
	bool interactive { false };
	bool verbose { false };
	bool flag_view { false };

	void Print() const {
		std::cerr << "Configuration: \n"
	    << " space = " << space << "\n"
		<< " radius = " << radius << "\n"
		<< " count points = " << count_points << "\n"
		<< " axis offset = " << axis_shift << "\n"
	    << " interactive: " << (interactive ? "yes" : "no") << "\n"
		<< " verbose: " << (verbose ? "yes" : "no") << "\n"
		<< " flag view: " << (flag_view ? "yes" : "no") << std::endl;
	}

};

ProgramConfig parse_command_line(int argc, char* argv[]);
void PrintUsage(const char* prog_name);
