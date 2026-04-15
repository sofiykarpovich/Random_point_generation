#pragma once

#include "formatter.h"

class CsvFormatter : public Formatter {
public:
    explicit CsvFormatter(char del = ',') : delimiter(del), Formatter() {}

    std::string FormatPoints(const int value, size_t& cnt, size_t& cnt_c) const;

private:
    char delimiter;
};