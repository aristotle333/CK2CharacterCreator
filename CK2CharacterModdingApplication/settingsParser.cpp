#include "settingsParser.h"

void readSettingsFile() {
    ifstream ifs("settings.txt");
    if (ifs.is_open()) {
        settingsAttributes& setAttr = settingsAttributes::get_instance();

        setAttr.start_date = readSettingsIntAttr("start_date", ifs);
        setAttr.culture = readSettingsStringAttr("culture", ifs);
        setAttr.religion = readSettingsStringAttr("religion", ifs);
        setAttr.character_id_from_province_multiplier = readSettingsIntAttr("character_id_from_province_multiplier", ifs);
        setAttr.dynasty_id_from_province_multiplier = readSettingsIntAttr("dynasty_id_from_province_multiplier", ifs);
        setAttr.mean_age_of_character_head = readSettingsIntAttr("mean_age_of_character_head", ifs);
        setAttr.age_variance_of_character_head = readSettingsIntAttr("age_variance_of_character_head", ifs);
        setAttr.mean_number_of_traits = readSettingsIntAttr("mean_number_of_traits", ifs);
        setAttr.number_of_traits_variance = readSettingsIntAttr("number_of_traits_variance", ifs);
        setAttr.mean_skill_values = readSettingsIntAttr("mean_skill_values", ifs);
        setAttr.skill_values_variance = readSettingsIntAttr("skill_values_variance", ifs);
        setAttr.mean_life_expectancy = readSettingsIntAttr("mean_life_expectancy", ifs);
        setAttr.life_expectancy_variance = readSettingsIntAttr("life_expectancy_variance", ifs);
    }
    else {
        std::cerr << "Unable to open settings.txt\n";
        throw std::exception();
    }
    ifs.close();
}

string readSettingsStringAttr(const string& attributeName, ifstream& ifs) {
    string line;
    if (getline(ifs, line)) {
        istringstream iss(line);
        string attr, dummy, value;
        iss >> attr >> dummy >> value;
        if (attr != attributeName || dummy != "=") {
            std::cerr << "Attribute name for " + attributeName + " in settings.txt is incorrect or syntax is incorrect\n";
            throw std::exception();
        }
        return value;        
    }
    else {
        std::cerr << "Missing or misplaced line for " + attributeName + " in settings.txt\n";
        throw std::exception();
    }
}

int readSettingsIntAttr(const string& attributeName, ifstream& ifs) {
    string line;
    if (getline(ifs, line)) {
        istringstream iss(line);
        string attr, dummy; int value;
        iss >> attr >> dummy >> value;
        if (attr != attributeName || dummy != "=") {
            std::cerr << "Attribute name for " + attributeName + " in settings.txt is incorrect or syntax is incorrect\n";
            throw std::exception();
        }
        return value;
    }
    else {
        std::cerr << "Missing or misplaced line for " + attributeName + " in settings.txt\n";
        throw std::exception();
    }
}