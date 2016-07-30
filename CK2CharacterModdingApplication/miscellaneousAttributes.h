#pragma once
#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;

struct miscellaneousAttributes {

    // Singleton Instance
    static miscellaneousAttributes& get_instance() {
        static miscellaneousAttributes instance;
        return instance;
    }

    miscellaneousAttributes(miscellaneousAttributes const &) = delete;
    miscellaneousAttributes(miscellaneousAttributes&&) = delete;

    //--- Attribute Variables --- //

    // Provinces related
    unordered_map<int, string> provinceIDNameMap;

    // Names Related
    string cultureNamesPath;
    vector<string> maleNames;
    vector<string> femaleNames;

private:
    miscellaneousAttributes() {}
};