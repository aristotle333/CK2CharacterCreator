#include "characterCreator.h"

struct characterAttributes {
    unordered_set<string> maleNames, femaleNames;
    int currentID;      // The latest unused character ID
    int headID;         // The character ID of the head
    int headAge;        // The age of the head of the dynasty

    int getNextID() const {
        return currentID + 1;
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
            charAttr.headID = settAttr.character_id_from_province_multiplier * provIDName.first;    // IDs headID + 1 and headID + 2 are reserved for the parents of the current head of dynasty
            charAttr.currentID = charAttr.headID;

            // Create the head
            CreateCharacter(true, false, false, charAttr, ofs);

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

void CreateCharacter(bool isDynastic, bool isFemale, bool hasSpouse, characterAttributes& charAttr, ofstream& ofs) {
    settingsAttributes& settAttr = settingsAttributes::get_instance();
    // Create ID
    ofs << charAttr.currentID << " = {\n";
    // Create name
    ofs << "\t" << "name=\"" << CreateName(isFemale, charAttr) << "\"\n";

    // TODO ADD Dynasty Creation here

    // Create culture and religion
    ofs << "\t" << "culture=\"" << settAttr.culture << "\"\t" << "religion=\"" << settAttr.religion << "\"\n";
    // Create skills
    ofs << "\t" << CreateSkills() << "\n";

    // TODO ADD Trait Creation here

    // Create parents for dynastic members except for the father of the current Head of the dynasty
    if (isDynastic && (charAttr.currentID != charAttr.headID + 1)) {
        ofs << "\t" << "father=" << charAttr.headID + 1 << "\t" << "mother=" << charAttr.headID + 2 << "\n";
    }
    // Create birth
    pair<int, string> birthDate = CreateBirthDate(isFemale, charAttr);
    ofs << "\t" << birthDate.second << "={birth=yes}\n";
    // Create marriage for a brother if hasSpouse == true
    if (hasSpouse) {
        ofs << "\t" << CreateMariageDate(birthDate.first) << "={add_spouse=" << charAttr.currentID + 1 << "}\n";
    }
    // Create death
    ofs << "\t" << 

}

string CreateName(bool isFemale, characterAttributes& charAttr) {
    miscellaneousAttributes& miscAttr = miscellaneousAttributes::get_instance();
    if (isFemale) {
        string randomFemaleName = miscAttr.femaleNames[randNumInRange(0, miscAttr.femaleNames.size())];
        while (charAttr.femaleNames.count(randomFemaleName)) {
            randomFemaleName = miscAttr.femaleNames[randNumInRange(0, miscAttr.femaleNames.size())];
        }
        charAttr.femaleNames.emplace(randomFemaleName);
        return randomFemaleName;
    }
    else {
        string randomMaleName = miscAttr.maleNames[randNumInRange(0, miscAttr.maleNames.size())];
        while (charAttr.maleNames.count(randomMaleName)) {
            randomMaleName = miscAttr.maleNames[randNumInRange(0, miscAttr.maleNames.size())];
        }
        charAttr.maleNames.emplace(randomMaleName);
        return randomMaleName;
    }
}

string CreateSkills() {
    settingsAttributes& settAttr = settingsAttributes::get_instance();
    int mean = settAttr.mean_skill_values;
    int variance = settAttr.skill_values_variance;
    string res;
    res = "diplomacy=" + to_string(randNumWithVar(mean, variance)) + "\t";
    res += "martial=" + to_string(randNumWithVar(mean, variance)) + "\t";
    res += "stewardship=" + to_string(randNumWithVar(mean, variance)) + "\t";
    res += "intrigue=" + to_string(randNumWithVar(mean, variance)) + "\t";
    res += "learning=" + to_string(randNumWithVar(mean, variance));
    return res;
}

// Returns the birth year as an in and the full birth date as a string
pair<int, string> CreateBirthDate(bool isFemale, characterAttributes& charAttr) {
    int year, month, day;
    settingsAttributes& settAttr = settingsAttributes::get_instance();
    // Check if we create the head
    if (charAttr.currentID == charAttr.headID) {
        year = randNumWithVar(settAttr.start_date - settAttr.mean_age_of_character_head, settAttr.age_variance_of_character_head);
        charAttr.headAge = settAttr.start_date - year;
    }
    // Check if we create parents of the head
    else if (charAttr.currentID == charAttr.headID + 1 || charAttr.currentID == charAttr.headID + 2) {
        year = randNumWithVar(settAttr.start_date - charAttr.headAge - 30, 5);
    }
    // Check if we create sisters for the head or spouses for head's brother (they can be older than head)
    else if (isFemale) {
        year = randNumWithVar(settAttr.start_date - charAttr.headAge, settAttr.age_variance_of_character_head);
    }
    // Check if we create brothers of the head (they must be younger than the head)
    else {
        year = randNumInRange(settAttr.start_date - charAttr.headAge + 1,
                              settAttr.start_date - charAttr.headAge + settAttr.age_variance_of_character_head);
    }

    month = randNumInRange(1, 12);
    day = randNumInRange(1, 28);
    string dateString = to_string(year) + "." + to_string(month) + "." + to_string(day);
    return pair<int, string>(year, dateString);
}

string CreateMariageDate(int maleAge) {
    int year, month, day;
    settingsAttributes& settAttr = settingsAttributes::get_instance();
    int adultYear = settAttr.start_date - (maleAge - 17);
    year = randNumInRange(adultYear, settAttr.start_date);
    month = randNumInRange(1, 12);
    day = randNumInRange(1, 28);
    string dateString = to_string(year) + "." + to_string(month) + "." + to_string(day);
    return dateString;
}

string CreateDeathDate(int curr_age, characterAttributes& charAttr) {
    int year, month, day;
    settingsAttributes& settAttr = settingsAttributes::get_instance();
    // Make sure parents of current head are dead before the start date
    if (charAttr.currentID == charAttr.headID + 1 || charAttr.currentID == charAttr.headID + 2) {
        year = randNumInRange(settAttr.start_date - charAttr.headAge + 1, settAttr.start_date - 1);
    }
    // Death is after the start date for all other characters
    else {

    }
    month = randNumInRange(1, 12);
    day = randNumInRange(1, 28);
    string dateString = to_string(year) + "." + to_string(month) + "." + to_string(day);
}