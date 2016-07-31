#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <atlstr.h>
#include "provinceSetParser.h"
#include "culturesParser.h"
#include "namesParser.h"
#include "miscellaneousAttributes.h"
#include "characterCreator.h"
using std::sort;
using std::vector;
using std::string;

// Ran when clicking to find for which provinces characters should be generated
vector<string> readProvinces(const string& directory);

// Ran when clicking on the culture dropdown to display what are the available cultures
vector<string> readAvailableCultures();

// Converts a partial path to an absolute path
LPCTSTR PrintFullPathCultureNames(string& partialPathS);

// Generates the names list for the specified culture
void GenerateNamesList(const string& cultureNamesPath);

void CreateCharacterFiles(const string& charactersOutputPath);