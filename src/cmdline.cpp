#include "../include/cmdline.h" 
#include "../include/formatter_factory.h"

#include <getopt.h>
#include <cstdlib>

void PrintUsage(const char* program_name) {
    std::cerr << "Usage: " << program_name << " [options]\n"
        << "Required options:\n"
        << "  -s, --space   N    Dimension space \n"
        << "  -r, --radius  N    Radius\n"
        << "  -a, --amount  N    Amount points\n"
        << "  -o, --offset  N    Cluster shift along the listed axes\n"
        << "  -c, --conclusion   File's name which will be recorded\n\n"
        << "Additional options:\n"
        << "  -i, --interactive Interactive mode\n"
        << "  -v, --verbose     Detailed output\n"
        << "  -d, --details     Show detailed output (with comments)\n"
        << "  -f, --format      Data recoding format | Output format: "
        << FormatterFactory::GetFormat() << "\n"
        << "  -h, --help        Show help\n";
}

ProgramConfig parse_command_line(int argc, char* argv[]) {
    ProgramConfig config;

    static struct option long_options[] = {
        {"space",  required_argument, 0, 's'},
        {"radius", required_argument, 0, 'r'},
        {"amount",  required_argument, 0, 'a'},
        {"offset", required_argument, 0, 'o'},
        {"format", required_argument, 0, 'f'},
        {"conclusion", required_argument, 0, 'c'},
        {"interactive", no_argument, 0, 'i'},
        {"verbose", no_argument, 0, 'v'},
        {"ditails", no_argument, 0, 'd'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    int opt;
    int option_index = 0;


    while ((opt = getopt_long(argc, argv, "s:r:a:o:f:c:ivdh", long_options, &option_index)) != -1) {
        switch (opt) {
        case 's':
            config.space = std::atoi(optarg);
            break;
        case 'r':
            config.radius = std::atoi(optarg);
            break;
        case 'a':
            config.count_points = std::atoi(optarg);
            break;
        case 'o':
            config.axis_shift = optarg;
            break;
        case 'f':
            config.format = optarg;
            break;
        case 'c':
            config.conclusion = optarg;
            break;
        case 'i':
            config.interactive = true;
            break;
        case 'v':
            config.verbose = true;
            break;
        case 'd':
            config.flag_view = true;
            break;
        case 'h':
            PrintUsage(argv[0]);
            exit(0);  
        default:
            PrintUsage(argv[0]);
            exit(1);
        }
    }

    return config;
}
