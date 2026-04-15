#include <sstream>

#include "../include/json_formatter.h"
#include "../include/cmdline.h"

std::string JsonFormatter::FormatHeader() const {
    if(indent_){
        std::cerr << "{\n  \"points:\" [\n";
        return "{\n  \"points:\" [\n";
    }
    else{
        std::cerr << "\"points:\" [";
        return "\"points:\" [";
    }

}

std::string JsonFormatter::FormatPoints(const int value, size_t& cnt, size_t& cnt_c) const {
    std::stringstream ss;

    if(indent_ && cnt == 1) {
        ss << "  \n{";
        std::cerr << "  {";
    } if(!indent_ && cnt == 1) {
        ss << "{";
        std::cerr << "{";
    } 

    if(cnt != config->space){
        ss << "\n     \"" << cnt << "\" : " << value << "\",";
        std::cerr << "\n     \"" << cnt << "\" : " << "\"" << value << "\",";
    }
    
    if(cnt == config->space && cnt_c == config->count_points) {
        ss << "\n     \"" << cnt << "\" : " << value << "\"\n  }";
        std::cerr << "\n     \"" << cnt << "\" : " << "\"" << value << "\"\n  }";
    }if(cnt == config->space && cnt_c != config->count_points) {
        ss << "\n     \"" << cnt << "\" : " << value << "\"\n  },";
        std::cerr << "\n     \"" << cnt << "\" : " << "\"" << value << "\"\n  },";
        ++cnt_c;
    }

    ++cnt;
    return ss.str();
}
std::string JsonFormatter::FormatFooting() const {
    if(indent_){
        std::cerr << "\n ]\n}"; 
        return "\n ]\n}"; 
    } else{
        std::cerr << "]}";
        return "]}";
    }

}