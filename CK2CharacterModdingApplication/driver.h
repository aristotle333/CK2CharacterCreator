#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <atlstr.h>
#include "provinceSetParser.h"
#include "culturesParser.h"
using std::sort;
using std::vector;
using std::string;

// Ran when clicking to find for which provinces characters should be generated
vector<int> readProvinces(const string& directory);

// Ran when clicking on the culture dropdown to display what are the available cultures
vector<string> readAvailableCultures();

// Converts a partial path to an absolute path
LPCTSTR PrintFullPathCultureNames(string& partialPathS);