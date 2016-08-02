#pragma once
#include "miscellaneousAttributes.h"
#include "settingsAttributes.h"
#include "Utils.h"
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using std::string;
using std::ofstream;
using std::pair;
using std::unordered_set;
using std::to_string;

struct characterAttributes {
    unordered_set<string> maleNames, femaleNames;
    int currentID;      // The latest unused character ID
    int headID;         // The character ID of the head
    int headAge;        // The age of the head of the dynasty
    int provinceID;     // The ID the province used to generate the dynasty ID
};

// Creates all characters for the specified provinces based on the settings selected
void CreateCharacters(const string& characterOutputPath);

// Functions and Data structures used by the Character creator ONLY
void CreateCharacter(bool isDynastic, bool isFemale, bool hasSpouse, characterAttributes& charAttr, ofstream& ofs);
string CreateName(bool isFemale, characterAttributes& charAttr);
string CreateSkills();
pair<int, string> CreateBirthDate(bool isFemale, characterAttributes& charAttr);
string CreateMariageDate(int maleAge, characterAttributes& charAttr);
string CreateDeathDate(int curr_age, characterAttributes& charAttr);