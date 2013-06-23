#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>

namespace BoostProgramOptions = boost::program_options;

class LSCSettings
{
public:
    //    const std::vector<std::string> RECOGNIZED_SETTINGS_NAMES {
    //        "name","name2"
    //    };

    static std::string getSettingsFilePath();
    static void writeSettings(std::map<std::string,std::string> settingsMap);
    static void writeString(std::string optionName, std::string optionValue, std::map<std::string,std::string> settingsMap);
    static void writeString(std::string optionName, std::string optionValue);
    static void readSettings(BoostProgramOptions::options_description& desc, BoostProgramOptions::variables_map& vm);
    static void readSettings(BoostProgramOptions::options_description& desc, BoostProgramOptions::variables_map& vm , bool allowUnregistered);
    static BoostProgramOptions::options_description getSettingsSemantics();
    static std::string getString(std::string optionName);
    static std::string getStringWithSchema(std::string optionName);
    static std::string getStringWithoutSchema(std::string optionName);
    static std::vector<std::string> getSettingsNames();
    static std::map<std::string,std::string> getSettingsMap();
};
