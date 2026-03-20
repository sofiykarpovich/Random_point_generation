#include "creating_a_cluster.h"

#include <algorithm>
#include <chrono>
#include <string>


std::set<std::vector<int>>& CloudPoints::GenerationRandomValueOnSpaceCircle(const int space, const int radius, const int count_point) {
    num_vec_.reserve(space);


    for (size_t i{ 0 }; i < count_point; ++i) {
        int s = radius * radius;

        for (size_t j{ 0 }; j < space; j++) {
            std::uniform_int_distribution<int> b(0, s);
            const int a = b(gen);
            
            std::uniform_real_distribution<> c(0, 1);
            const double d = c(gen);

            std::uniform_int_distribution<int> point_x_i(0, s*d);
            const int x = static_cast<int>(std::sqrt(point_x_i(gen)));

            num_vec_.push_back([x, a](){
                return (a % 2 == 0) ? -x : x;
            }()); 
            s -= x * x;
        }
        
        Shake(num_vec_);
        space_coordinates_n_.insert(num_vec_);
        num_vec_.clear();
    }
    return space_coordinates_n_;
}

void CloudPoints::Shake(std::vector<int>& array) { 

    for(size_t i{0}; i < array.size() - 1; ++i){
        size_t capacity = array.size() - 1;
        std::uniform_int_distribution<int> distance(i, capacity);

        const int new_index = distance(gen);
        std::swap(array[i], array[new_index]);
    }
}

void CloudPoints::PrintRandomValueOnSpaceCircle(std::set<std::vector<int>>& coordinates_space_n, bool edit, bool shift) const {
    if(edit){
        std::cerr << "\nPoints: " << std::endl;
        for (const std::vector<int>& point : coordinates_space_n) {
            std::cerr << "{";
            for(size_t i{0}; i < point.size() - 1; ++i){
                    std::cout << point[i] << ", ";
                    std::cerr << point[i] << ", ";
            }
            std::cout << point.back();
            std::cerr << point.back();
            std::cerr << "}" << "\n";
        }

    }if(shift){
        for (const std::vector<int>& point : coordinates_space_n) {
            for(size_t i{0}; i < point.size() - 1; ++i){
                    std::cout << point[i] << ", ";
            }
            std::cout << point.back();
        }
    }
    

}
