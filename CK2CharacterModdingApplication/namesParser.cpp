#include "namesParser.h"

void NamesListParser(const string& cultureNamesPath) {
    ifstream ofs(cultureNamesPath);
    if (ofs.is_open()) {
        miscellaneousAttributes& miscAttr = miscellaneousAttributes::get_instance();
        vector<string>& male_names = miscAttr.maleNames;
        vector<string>& female_names = miscAttr.femaleNames;
        male_names.clear();
        female_names.clear();

        string curr;    // The current read string
        while (ofs >> curr) {
            // Read male names            
            if (!CheckForString(curr, "male_names", cultureNamesPath, ofs)) {
                throw std::exception();
            }
            ofs >> curr;
            if (!CheckForString(curr, "=", cultureNamesPath, ofs)) {
                throw std::exception();
            }
            ofs >> curr;
            if (!CheckForString(curr, "{", cultureNamesPath, ofs)) {
                throw std::exception();
            }
            while (ofs >> curr) {
                if (curr == "}") {
                    break;      // Done reading male_names;
                }
                male_names.emplace_back(curr);
            }

            ofs >> curr;
            // Read female names
            if (!CheckForString(curr, "female_names", cultureNamesPath, ofs)) {
                throw std::exception();
            }
            ofs >> curr;
            if (!CheckForString(curr, "=", cultureNamesPath, ofs)) {
                throw std::exception();
            }
            ofs >> curr;
            if (!CheckForString(curr, "{", cultureNamesPath, ofs)) {
                throw std::exception();
            }
            while (ofs >> curr) {
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
    ofs.close();
}


bool CheckForString(const string& input, const string& target, const string& path, ifstream& ofs){
    if (input != target) {
        std::cerr << "Error at reading names. Check the syntax of the file " + path;
        ofs.close();
        return false;
    }
    else {
        return true;
    }
}