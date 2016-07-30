#pragma once
#include <string>
#include <unordered_set>
#include <dirent.h>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
using std::string;
using std::unordered_set;
using std::stringstream;
using std::exception;
using std::vector;

// Reads a specified Directory for province files. Province files names must start with their province id(number)
vector<int> readProvincesDirectory(const string& directory);