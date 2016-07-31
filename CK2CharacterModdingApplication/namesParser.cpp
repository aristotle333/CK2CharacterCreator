#include "namesParser.h"

void NamesListParser(const string& cultureNamesPath) {
    ifstream ifs(cultureNamesPath);
    if (ifs.is_open()) {
        miscellaneousAttributes& miscAttr = miscellaneousAttributes::get_instance();
        vector<string>& male_names = miscAttr.maleNames;
        vector<string>& female_names = miscAttr.femaleNames;
        male_names.clear();
        female_names.clear();

        string curr;    // The current read string
        while (ifs >> curr) {
            // Read male names            
            if (!CheckForString(curr, "male_names", cultureNamesPath, ifs)) {
                throw std::exception();
            }
            ifs >> curr;
            if (!CheckForString(curr, "=", cultureNamesPath, ifs)) {
                throw std::exception();
            }
            ifs >> curr;
            if (!CheckForString(curr, "{", cultureNamesPath, ifs)) {
                throw std::exception();
            }
            while (ifs >> curr) {
                if (curr == "}") {
                    break;      // Done reading male_names;
                }
                male_names.emplace_back(curr);
            }

            ifs >> curr;
            // Read female names
            if (!CheckForString(curr, "female_names", cultureNamesPath, ifs)) {
                throw std::exception();
            }
            ifs >> curr;
            if (!CheckForString(curr, "=", cultureNamesPath, ifs)) {
                throw std::exception();
            }
            ifs >> curr;
            if (!CheckForString(curr, "{", cultureNamesPath, ifs)) {
                throw std::exception();
            }
            while (ifs >> curr) {
                if (curr == "}") {
                    break;      // Done reading female_names;
                }
                female_names.emplace_back(curr);
            }
        }   // End of outer While Loop
    }
    else {
        std::cerr << "Unable to open the culture file at " + cultureNamesPath;
        throw std::exception();
    }
    ifs.close();
}


bool CheckForString(const string& input, const string& target, const string& path, ifstream& ifs){
    if (input != target) {
        std::cerr << "Error at reading names. Check the syntax of the file " + path;
        ifs.close();
        return false;
    }
    else {
        return true;
    }
}