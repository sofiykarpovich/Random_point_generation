#include <sstream>

#include "../include/csv_formatter.h"
#include "../include/creating_a_cluster.h"
#include "../include/cmdline.h"


std::string CsvFormatter::FormatPoints(const int value, size_t& cnt, size_t& cnt_c) const {
    std::stringstream ss;
    if(cnt >= 1 && cnt != config->space) {
        ss << "\n" << value << ",";
        std::cerr << value << ",";
        ++cnt;
    }else{
        ss << value << "\n";
        std::cerr << value << "\n";
    }
        
    return ss.str();
}