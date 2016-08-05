#include "provinceSetParser.h"

// Reads a specified Directory for province files. Province files names must start with their province id(number)
vector<string> readProvincesDirectory(const string& directory) {
    // Singleton Reference
    miscellaneousAttributes& miscAttr = miscellaneousAttributes::get_instance();

    DIR *dir;
    struct dirent *ent;
    unordered_map<int, string>& provincesSet = miscAttr.provinceIDNameMap;
    provincesSet.clear();
    if ((dir = opendir(directory.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            stringstream ss;
            int provinceID; string dummy, provinceNameFull;
            ss << ent->d_name;
            if (ss >> provinceID >> dummy >> provinceNameFull) {
                string provinceName = provinceNameFull.substr(0, provinceNameFull.find("."));
                if (!provincesSet.count(provinceID)) {
                    provincesSet.emplace(provinceID, provinceName);
                }
                else {
                    std::cerr << "Duplicate province ID detected, check province files at " + directory;
                    throw exception();
                }
            }
        }
        closedir(dir);
    }
    else {
        std::cerr << "Unable to parse directory";
        throw exception();
    }

    // Sort the result to look nicely
    vector<int> keys;
    keys.reserve(provincesSet.size());
    for (auto& it : provincesSet) {
        keys.push_back(it.first);
    }
    std::sort(keys.begin(), keys.end());
    vector<string> res;
    res.reserve(keys.size());
    for (auto& provID : keys) {
        res.push_back(std::to_string(provID) + " " + provincesSet[provID]);
    }
    return res;
}