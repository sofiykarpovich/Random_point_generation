#include "cmdline.h"
#include "creating_a_cluster.h"

#include <iostream>

int main(int argc, char* argv[]) {

    ProgramConfig config = parse_command_line(argc, argv);

    if (config.interactive || config.space == 0 || config.radius == 0 || config.count_points == 0) {
        std::cout << "Interactive inpute mode \n";

        if (config.space == 0) {
            std::cout << "Enter space: ";
            std::cin >> config.space;
        }
        if (config.radius == 0) {
            std::cout << "Enter radius: ";
            std::cin >> config.radius;
        }
        if (config.count_points == 0) {
            std::cout << "Enter count_points: ";
            std::cin >> config.count_points;
        }
    }


    if (config.space <= 0 || config.radius <= 0 || config.count_points <= 0) {
        std::cerr << "Erorr!\n";
        return 1;
    }


    if (config.verbose) {
        config.Print();
    }


    CloudPoints points{ config.space, config.radius, config.count_points };
    auto& points_1 = points.GenerationRandomValueOnSpaceCircle(
        config.space, config.radius, config.count_points);
    points.PrintRandomValueOnSpaceCircle(points_1);
    points.PrintRandomValueOnSpaceCircle(points.ShiftTo(points_1));

    return 0;
}
