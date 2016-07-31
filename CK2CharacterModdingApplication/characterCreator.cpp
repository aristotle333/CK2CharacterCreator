#include "characterCreator.h"

void CreateCharacters(const string& characterOutputPath) {
    // Get references to singletons
    miscellaneousAttributes& miscAttr = miscellaneousAttributes::get_instance();
    settingsAttributes& settAttr = settingsAttributes::get_instance();

    // Loop through every province
    for (pair<int, string> provIDName : miscAttr.provinceIDNameMap) {
        ofstream ofs(characterOutputPath + "\\" + to_string(provIDName.first) + " - " + provIDName.second + " - " + "Characters.txt");

        if (ofs.is_open()) {
            unordered_set<string> maleNames, femaleNames;


            ofs.close();
        }
        else {
            
        }


    }

    return;
}