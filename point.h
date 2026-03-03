#pragma once
#include <iostream>
#include <set>
#include <random>
#include <vector>
#include <utility>

class CloudPoints {
public:

    CloudPoints(const int space, const int radius, const int count_points) :
        space_(space), radius_(radius), count_points_(count_points) {
        gen.seed(rd());
    }


    void Shake(std::vector<int>& array);
    std::set<std::vector<int>>& GenerationRandomValueOnSpaceCircle(const int space, const int radius, const int count_point);
    void PrintRandomValueOnSpaceCircle(std::set<std::vector<int>>& coordinates_space_n) const;
    std::set<std::vector<int>>& ShiftTo(std::set<std::vector<int>>& coordinates_space_n);

private:
    int space_, radius_, count_points_;
    std::set<std::vector<int>> space_coordinates_n_;
    std::vector<int> num_vec_;
    std::mt19937 gen;
    std::random_device rd;
};
