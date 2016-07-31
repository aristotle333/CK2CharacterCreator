#pragma once
#include "settingsAttributes.h"
#include <fstream>
#include <iostream>
#include <sstream>
using std::ifstream;
using std::istringstream;
using std::getline;

// Reads the parses the settings.txt file
void readSettingsFile();


// Functions used by settings.cpp ONLY
string readSettingsStringAttr(const string& attributeName, ifstream& ifs);
int readSettingsIntAttr(const string& attributeName, ifstream& ifs);