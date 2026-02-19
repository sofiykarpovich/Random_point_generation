#include "point.h"
#include <algorithm>
#include <chrono>

/*
void CloudPoints::GenerationVector(std::vector<int>& create_vector, const int size, int s, int current = 0) {
    if(current == size) return;
        std::uniform_int_distribution<int> b(0, s);
            const int a = b(gen);
            
            std::uniform_real_distribution<> c(0, 1);
            const double d = c(gen);

            std::uniform_int_distribution<int> point_x_i(0, s * d);
            const int x = sqrt(point_x_i(gen));

            num_vec_.push_back((a % 2 == 0) ? -x : x); 
            s -= x * x;
    GenerationVector(num_vec_, size, s, ++current);

}
*/

std::set<std::vector<int>>& CloudPoints::GenerationRandomValueOnSpaceCircle(const int space, const int radius, const int count_point) {
   
    std::cout << "Space: " << space << std::endl;
    std::cout << "Radius: " << radius << std::endl;

    for (size_t i{ 0 }; i < count_point; ++i) {
        int s = radius * radius;


        /*auto start = std::chrono::high_resolution_clock::now();

        GenerationVector(num_vec_, space, s);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Time work: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;*/
        

        //auto start = std::chrono::high_resolution_clock::now();
        for (size_t j{ 0 }; j < space; ++j) {
            std::uniform_int_distribution<int> b(0, s);
            const int a = b(gen);
            
            std::uniform_real_distribution<> c(0, 1);
            const double d = c(gen);

            std::uniform_int_distribution<int> point_x_i(0, s*d);
            const int x = sqrt(point_x_i(gen));

            num_vec_.push_back([x, a](){
                return (a % 2 == 0) ? -x : x;
            }()); 
            s -= x * x;
        }
        //auto end = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double> duration = end - start;
        //std::cout << "Time work: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
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

        int new_index = distance(gen);
        std::swap(array[i], array[new_index]);
    }

}

void CloudPoints::PrintRandomValueOnSpaceCircle(std::set<std::vector<int>>& coordinates_space_n) {
    std::cout << "Points: " << std::endl;
    for (const std::vector<int>& point : coordinates_space_n) {
        std::cout << "{";
        for(size_t i{0}; i < point.size() - 1; ++i){
            std::cout << point[i] << ", ";
        }
        std::cout << point.back();
        std::cout << "}" << "\n";
    }

}

std::set<std::vector<int>>& CloudPoints::ShiftTo(std::set<std::vector<int>>& space_coordinates_n_) {
    std::set<std::vector<int>> result;

    std::uniform_int_distribution<int> shift(radius_ + 1, 1000);
    const int shift_to = shift(gen);
    std::uniform_int_distribution<int> axis(0, space_ - 1);
    int a = axis(gen);

    std::cout << "\nShift to " << shift_to << " on " << a + 1 << " axis" << std::endl;
    
    for (const std::vector<int>& point : space_coordinates_n_) {
        std::vector<int> modif_vec = point;    
        std::uniform_int_distribution<int> b(0, 100);
        const int a_1 = b(gen);

        const int sign = (a_1 % 2 == 0) ? shift_to : -(shift_to);

        modif_vec[a] += sign;
        result.insert(modif_vec);
    }
    space_coordinates_n_.clear();
    std::swap(space_coordinates_n_, result);
    result.clear();
    return space_coordinates_n_;
}

int main() {
    int space, radius, count_points;
    std::cout << "Enter space: ";
    std::cin >> space;
    for (size_t i{ 0 }; i < 3; ++i) {

        std::cout << "Enter radius, count_points: ";
        std::cin >> radius >>count_points;

        CloudPoints points{space, radius, count_points};
        auto& points_1 = points.GenerationRandomValueOnSpaceCircle(space, radius, count_points);
        points.PrintRandomValueOnSpaceCircle(points_1);

        points.PrintRandomValueOnSpaceCircle(points.ShiftTo(points_1));
    }
}