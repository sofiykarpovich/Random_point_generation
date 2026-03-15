#include "cmdline.h" 

#include <getopt.h>
#include <cstdlib>

void PrintUsage(const* char program_name) const {
    std::cout << "Usage: " << program_name << " [options]\n"
        << "Required options:\n"
        << "  -s, --space N     Dimension space \n"
        << "  -r, --radius N    Radius\n"
        << "  -a, --amount N     Amount points\n\n"
        << "Additional options:\n"
        << "  -i, --interactive Interactive mode\n"
        << "  -v, --verbose     Detailed output\n"
        << "  -h, --help        Show help\n";
}

ProgramConfig parse_command_line(int argc, char* argv[]) {
    ProgramConfig config;

    static struct option long_options[] = {
        {"space",  required_argument, 0, 's'},
        {"radius", required_argument, 0, 'r'},
        {"count",  required_argument, 0, 'c'},
        {"interactive", no_argument, 0, 'i'},
        {"verbose", no_argument, 0, 'v'},
        {"help",   no_argument,       0, 'h'},
        {0, 0, 0, 0}
    };

    int opt;
    int option_index = 0;

    while ((opt = getopt_long(argc, argv, "s:r:c:ivh", long_options, &option_index)) != -1) {
        switch (opt) {
        case 's':
            config.space = std::atoi(optarg);
            break;
        case 'r':
            config.radius = std::atoi(optarg);
            break;
        case 'c':
            config.count_points = std::atoi(optarg);
            break;
        case 'i':
            config.interactive = true;
            break;
        case 'v':
            config.verbose = true;
            break;
        case 'h':
            print_usage(argv[0]);
            exit(0);  
        default:
            print_usage(argv[0]);
            exit(1);
        }
    }

    return config;
}