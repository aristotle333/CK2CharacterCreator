#pragma once
#include "miscellaneousAttributes.h"
#include "settingsAttributes.h"
#include <unordered_set>
#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <stdexcept>
using std::string;
using std::ofstream;
using std::pair;
using std::unordered_set;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::to_string;

// Creates all characters for the specified provinces based on the settings selected
void CreateCharacters(const string& characterOutputPath);