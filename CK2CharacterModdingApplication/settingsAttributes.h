#pragma once
#include <string>
using std::string;

struct settingsAttributes {

    // Singleton Instance
    static settingsAttributes& get_instance() {
        static settingsAttributes instance;
        return instance;
    }

    settingsAttributes(settingsAttributes const &) = delete;
    settingsAttributes(settingsAttributes&&) = delete;

    //--- Attribute Variables --- //
    int start_date;
    string culture;
    string religion;
    int character_id_from_province_multiplier;
    int mean_age_of_character_head;			
    int age_variance_of_character_head;
    int mean_number_of_traits;
    int number_of_traits_variance;
    int mean_skill_values;
    int skill_values_variance;
    int mean_life_expectancy;
    int life_expectancy_variance;

private:
    settingsAttributes() {}
};