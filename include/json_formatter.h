#pragma once

#include "formatter.h"

class JsonFormatter : public Formatter {
public:
    explicit JsonFormatter(bool indent = true) : indent_(indent) {}

    std::string FormatHeader() const override;
    std::string FormatPoints(const int value, size_t& cnt, size_t& cnt_c) const override;
    std::string FormatFooting() const override;

private:
    bool indent_; 
};