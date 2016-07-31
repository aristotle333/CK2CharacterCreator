#include "characterCreator.h"

struct characterAttributes {
    unordered_set<string> maleNames, femaleNames;
    int currentID;      // The current ID of the latest character
    int headAge;        // The age of the head of the dynasty

    int getNextID() const {
        return currentID;
    }
};

void CreateCharacters(const string& characterOutputPath) {
    // Get references to singletons
    miscellaneousAttributes& miscAttr = miscellaneousAttributes::get_instance();
    settingsAttributes& settAttr = settingsAttributes::get_instance();

    // Loop through every province
    for (pair<int, string> provIDName : miscAttr.provinceIDNameMap) {
        ofstream ofs(characterOutputPath + "\\" + to_string(provIDName.first) + " - " + provIDName.second + " - " + "Characters.txt");

        if (ofs.is_open()) {
            characterAttributes charAttr;
            charAttr.currentID = settAttr.character_id_from_province_multiplier * provIDName.first;    // IDs headID + 1 and headID + 2 are reserved for the current head of dynasty

            // Create the head
            createCharacter(true, false, charAttr, ofs);

            // Create the parents

            

            ofs.close();
        }
        else {
            std::cerr << "Failed to create the character file for the province of " + provIDName.second + "\n";
            throw std::exception();
        }


    }

    return;
}

void createCharacter(bool isDynastic, bool isFemale, characterAttributes& charAttr, ofstream& ofs) {


}