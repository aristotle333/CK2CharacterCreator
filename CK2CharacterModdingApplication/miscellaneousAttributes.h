#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

struct miscellaneousAttributes {

    // Singleton Instance
    static miscellaneousAttributes& get_instance() {
        static miscellaneousAttributes instance;
        return instance;
    }

    miscellaneousAttributes(miscellaneousAttributes const &) = delete;
    miscellaneousAttributes(miscellaneousAttributes&&) = delete;

    // Attribute Variables
    string cultureNamesPath;
    vector<string> maleNames;
    vector<string> femaleNames;

private:
    miscellaneousAttributes() {}
};