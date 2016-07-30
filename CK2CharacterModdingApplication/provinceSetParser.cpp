#include "provinceSetParser.h"

// Reads a specified Directory for province files. Province files names must start with their province id(number)
vector<int> readProvincesDirectory(const string& directory) {
    DIR *dir;
    struct dirent *ent;
    unordered_set<int> provincesSet;
    if ((dir = opendir(directory.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            stringstream ss;
            int provinceID;
            ss << ent->d_name;
            if (ss >> provinceID) {
                if (!provincesSet.count(provinceID)) {
                    provincesSet.emplace(provinceID);
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

    vector<int> res(provincesSet.begin(), provincesSet.end());
    // Sort the vector to look nicely in the output window
    std::sort(res.begin(), res.end());
    return res;
}