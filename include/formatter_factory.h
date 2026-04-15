#pragma once

#include <functional>
#include <memory>
#include <map>

#include "formatter.h"
#include "json_formatter.h"
#include "csv_formatter.h"

class FormatterFactory {
public:
    static std::unique_ptr<Formatter> create (const std::string& format){
        static const std::map<std::string, std::function<std::unique_ptr<Formatter>()>> creators = {
            { "json", []() -> std::unique_ptr<Formatter> { return std::make_unique<JsonFormatter>(true); } },
            { "json-compact", []() -> std::unique_ptr<Formatter> { return std::make_unique<JsonFormatter>(false); } },
            { "csv", []() -> std::unique_ptr<Formatter> { return std::make_unique<CsvFormatter>(','); } }
        };
        auto it = creators.find(format);
        return it != creators.end() ? it->second() : nullptr;
    }

    static std::string GetFormat(){
        return "json, json-compact, csv";
    }
};