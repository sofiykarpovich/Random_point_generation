#include "point.h"
#include <sstream>

std::set<std::vector<int>>& CloudPoints::ShiftTo(std::set<std::vector<int>>& space_coordinates_n_) {

    std::set<std::vector<int>> result;
    std::string axis_shifting{};

    std::cout << "\nWhich axis do you want to move the cloud points?  (e.g., '1,2,3' or '1-3'):  " << std::endl;
    std::cin >> axis_shifting;


    std::vector<int> selected_axes;
    std::stringstream ss(axis_shifting);
    std::string token;


    while (std::getline(ss, token, ',')) {
        size_t dash_pos = token.find('-'); 
        if (dash_pos != std::string::npos) {
            const int start = std::stoi(token.substr(0, dash_pos));
            const int end = std::stoi(token.substr(dash_pos + 1));
            for (int i{ start }; i <= end; ++i) {
                if (i >= 1 && i <= static_cast<int>(space_coordinates_n_.begin()->size())) {
                    selected_axes.push_back(i - 1);  
                }
            }
        }
        else {
            int axis = std::stoi(token);
            if (axis >= 1 && axis <= static_cast<int>(space_coordinates_n_.begin()->size())) {
                selected_axes.push_back(axis - 1);
            }
        }
    }


    if (selected_axes.empty()) {
        std::cout << "No valid axes selected. Returning original set." << std::endl;
        return space_coordinates_n_;
    }


    std::vector<int> shift_values(selected_axes.size());
    std::uniform_int_distribution<int> shift_dist(radius_ + 1, 1000);
    std::uniform_int_distribution<int> direction_dist(0, 100);


    for (size_t i{ 0 }; i < selected_axes.size(); ++i) {
        shift_values[i] = (direction_dist(gen) % 2 == 0) ? shift_dist(gen) : -shift_dist(gen);
    }


    std::cout << "\nShifting by: \n";
    for (size_t i{ 0 }; i < selected_axes.size(); ++i) {
        std::cout << "axis " << selected_axes[i] + 1 << ": " << shift_values[i] << std::endl << std::endl;
    }
    std::cout << std::endl;


    for (const std::vector<int>& point : space_coordinates_n_) {
        std::vector<int> modified_point = point;

        for (size_t i{ 0 }; i < selected_axes.size(); ++i) {
            const int axis = selected_axes[i];
            modified_point[axis] += shift_values[i];
        }

        result.insert(std::move(modified_point));
    }

    space_coordinates_n_.clear();
    std::swap(space_coordinates_n_, result);
    result.clear();
    return space_coordinates_n_;
}
