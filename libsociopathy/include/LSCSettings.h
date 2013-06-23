#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>

namespace BoostProgramOptions = boost::program_options;

class LSCSettings
{
public:
    static void writeSettings(std::string name, std::string value );
    static void readSettings( BoostProgramOptions::options_description& desc, BoostProgramOptions::variables_map& vm );    
    static std::string getSettingsFilePath();
    static BoostProgramOptions::options_description getOptionDescription();
    static std::string getStringOption(std::string optionName);
    static string getStringOptionWithSchema(std::string optionName);
    static string getStringOptionWithoutSchema(std::string optionName);
};
