#pragma once
#include <string>
#include <unordered_map>
#include <dirent.h>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include "miscellaneousAttributes.h"
using std::string;
using std::unordered_map;
using std::stringstream;
using std::exception;
using std::vector;

// Reads a specified Directory for province files. Province files names must start with their province id(number)
vector<string> readProvincesDirectory(const string& directory);