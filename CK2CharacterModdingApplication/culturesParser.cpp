#include "culturesParser.h"

vector<string> availableCultures() {
    DIR *dir;
    struct dirent *ent;
    string namesPath = "names";
    unordered_set<string> culturesSet;
    if ((dir = opendir(namesPath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            string culture = ent->d_name;
            if (!culturesSet.count(culture)) {
                if (culture != "." && culture != "..") {
                    culturesSet.emplace(culture);
                }
            }
            else {
                std::cerr << "Duplicate culture decleration for culture " + culture;
                throw std::exception();
            }
        }
        closedir(dir);
    }
    else {
        std::cerr << "Unable to parse directory " + namesPath;
        throw std::exception();
    }

    // Sort culturesSet in a vector to be displayed nicely in dropdown
    vector<string> res(culturesSet.begin(), culturesSet.end());
    std::sort(res.begin(), res.end());
    return res;
}