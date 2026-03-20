#include "../include/cmdline.h"
#include "../include/creating_a_cluster.h"

#include <iostream>

int main(int argc, char* argv[]) {

    ProgramConfig config = parse_command_line(argc, argv);

    if (config.interactive || config.space == 0 || config.radius == 0 || config.count_points == 0 || config.axis_shift == "") {
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
        if(config.axis_shift == ""){
            std::cerr << "Enter axis shift: ";
            std::cin >> config.axis_shift;
        }
        else{
            std::cerr << "\nWhich axis do you want to move the cloud points?  (e.g., '1,2,3' or '1-3'):  ";
            std::cin >> config.axis_shift;
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


    CloudPoints points{ config.space, config.radius, config.count_points };
    auto& points_1 = points.GenerationRandomValueOnSpaceCircle(
        config.space, config.radius, config.count_points);
    points.PrintRandomValueOnSpaceCircle(points_1, config.flag_view);
    points.PrintRandomValueOnSpaceCircle(points.ShiftTo(points_1, config.axis_shift, config.flag_view), config.flag_view, true);

    return 0;
}
