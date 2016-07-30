#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "miscellaneousAttributes.h"
using std::ifstream;
using std::string;
using std::vector;

void NamesListParser(const string& cultureNamesPath);

bool CheckForString(const string& input, const string& target, const string& path, ifstream& ofs);