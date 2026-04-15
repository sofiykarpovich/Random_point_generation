#include "../include/cmdline.h"
#include "../include/creating_a_cluster.h"

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {

    ProgramConfig config = parse_command_line(argc, argv);
    auto formatter = FormatterFactory::create(config.format);

    if (config.interactive || config.space == 0 || config.radius == 0 || config.count_points == 0 || config.axis_shift == "" || config.conclusion == "") {
        std::cerr << "Interactive inpute mode \n";

        if (config.space == 0) {
            std::cerr << "Enter space: ";
            std::cin >> config.space;
        }
        if (config.radius == 0) {
            std::cerr << "Enter radius: ";
            std::cin >> config.radius;
        }
        if (config.count_points == 0) {
            std::cerr << "Enter count_points: ";
            std::cin >> config.count_points;
        }
        if(config.axis_shift == "") {
            std::cerr << "Which axis do you want to move the cloud points?\nEnter axis shift: ";
            std::cin >> config.axis_shift;
        }
        if(config.conclusion == "") {
            std::cerr << "By default, a file is created with name \"new_cluster\" with installed format";
            config.conclusion = "new_cluster";
        }
    }


    if (config.space <= 0 || config.radius <= 0 || config.count_points <= 0) {
        std::cerr << "ERORR! Argunents can't be negative.\n";
        return 1;
    }


    if (config.verbose) {
        config.Print();
    }


    if(config.flag_view){
        std::cerr << "\nSpace: " << config.space << std::endl;
        std::cerr << "Radius: " << config.radius << std::endl;
        std::cerr << "Amont points: " << config.axis_shift << std::endl;
    }
     

    if(!formatter){
        std::cerr << "Unsuppoeted format " << config.format << "\n";
        std::cerr << "Supported formats: " << FormatterFactory::GetFormat() << "\n";
        return 1;
    }

    
    if(formatter) {
        formatter->config = &config;
    }

    


    CloudPoints points{ config.space, config.radius, config.count_points };
    auto& points_1 = points.GenerationRandomValueOnSpaceCircle(
        config.space, config.radius, config.count_points);
    points.PrintRandomValueOnSpaceCircle(points_1, config.flag_view);
    points.PrintRandomValueOnSpaceCircle(points.ShiftTo(points_1, config.axis_shift, config.flag_view), config.flag_view, true);
    std::string output = formatter->FormatAll(points_1);
    std::string output_file = config.conclusion + "." + config.format;
    std::ofstream file(output_file);

    if(!file) {
        std::cerr << "Error: can't open file " << output_file;
        return 1;
    }
    file << output;
    std::cout << "\nData was saved to " << output_file << " in format " << config.format << "\n";
    return 0;
}
