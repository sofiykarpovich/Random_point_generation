#pragma once

#include <string>
#include <vector>
#include "../include/creating_a_cluster.h"

struct ProgramConfig; 

class Formatter { 
public:
    ProgramConfig* config = nullptr;
    Formatter() : config(nullptr) {}

    Formatter(ProgramConfig* cnf) : config(cnf) {}

    virtual std::string FormatHeader() const { return ""; }
    virtual std::string FormatPoints(const int value, size_t& cnt, size_t& cnt_c) const = 0;
    virtual std::string FormatFooting() const { return ""; }

    std::string FormatAll(const std::set<std::vector<int>>& cluster) const {
        std::cerr << "\n";
        std::string result = FormatHeader();
        for(size_t cnt_c = 1; const std::vector<int>& vector_points: cluster){
            for(size_t cnt = 1; const int& val : vector_points) {
                result += FormatPoints(val, cnt, cnt_c);
            }
        }
        result += FormatFooting() + "\n";
        return result;
    }

    virtual ~Formatter() = default;
};