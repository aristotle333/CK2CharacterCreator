#include "driver.h"

// Driver Includes all the functions called by the characterForm

vector<string> readProvinces(const string& directory) {
    return readProvincesDirectory(directory);
}

vector<string> readAvailableCultures() {
    return availableCultures();
}

LPCTSTR PrintFullPathCultureNames(string& partialPathS) {
    partialPathS = "names\\" + partialPathS;
    const char* partialPath = partialPathS.c_str();
    char full[_MAX_PATH];
    if (_fullpath(full, partialPath, _MAX_PATH) != NULL) {
        miscellaneousAttributes& misc = miscellaneousAttributes::get_instance();
        misc.cultureNamesPath = full;
        CString str(full);
        LPCTSTR res = str;
        return res;
    }
    else {
        std::cerr << "Could not resolve absolute path for the culture name file\n";
        throw exception();
    }
}

void GenerateNamesList(const string& cultureNamesPath) {
    NamesListParser(cultureNamesPath);
}

void CreateCharacterFiles(const string& charactersOutputPath) {
    CreateCharacters(charactersOutputPath);
}