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

// Creates all characters for the specified provinces based on the settings selected
void CreateCharacters(const string& characterOutputPath);