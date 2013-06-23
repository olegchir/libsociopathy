#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>

#include "LSCPlatformTools.h"
#include "LSCLang.h"

#include "LSCSettings.h"



void LSCSettings::writeSettings( std::string name, std::string value )
{
    std::ofstream settings_file( getSettingsFilePath() );
    settings_file << name << " = " << value.c_str();
    settings_file.close();
}

void LSCSettings::readSettings( BoostProgramOptions::options_description& desc, BoostProgramOptions::variables_map& vm )
{
    std::ifstream settings_file( getSettingsFilePath() );

    // Clear the map.
    vm = BoostProgramOptions::variables_map();    

    try {
        BoostProgramOptions::store( BoostProgramOptions::parse_config_file( settings_file , desc ), vm );
    } catch(std::exception const&  ex) {
        LSCLang::printException(ex);
    }

    settings_file.close();
    BoostProgramOptions::notify( vm );
}


string LSCSettings::getSettingsFilePath() {
    string fileName ("libsociopathy.ini");
    string homeDir = LSCPlatformTools::getUserHomeDir();
    string filePath (homeDir + FILE_SEPARATOR + fileName);
    return filePath;
}

string LSCSettings::getStringOption(std::string optionName)
{
    return getStringOptionWithoutSchema(optionName);
}

string LSCSettings::getStringOptionWithoutSchema(std::string optionName)
{    
    BoostProgramOptions::options_description desc("Options");
    desc.add_options()(optionName.c_str(), optionName.c_str() );

    BoostProgramOptions::variables_map vm;
    readSettings( desc, vm );

    std::string result("");
    BoostProgramOptions::variables_map::iterator it = vm.find(optionName);
    if (it != vm.end()) {
        BoostProgramOptions::variable_value value = it->second;
        boost::any any = value.value();
        result =  boost::any_cast< std::string >(any);
    }

    return result;
}

string LSCSettings::getStringOptionWithSchema(std::string optionName)
{
    std::string optionValue;
    // Setup options.
    BoostProgramOptions::options_description desc("Options");


    desc.add_options()
            (optionName.c_str(), BoostProgramOptions::value< std::string >( &optionValue ), optionName.c_str() );


    BoostProgramOptions::variables_map vm;
    readSettings( desc, vm );

    return optionValue;
}
