#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>

#include "LSCPlatformTools.h"
#include "LSCLang.h"

#include "LSCSettings.h"



void LSCSettings::writeSettings(std::map<std::string,std::string> settingsMap )
{
    std::ofstream settings_file( getSettingsFilePath() );
    for(std::map<std::string,std::string>::iterator it = settingsMap.begin(); it != settingsMap.end(); ++it) {
        settings_file << it->first << " = " << it->second << "\n";
    }
    settings_file.close();
}

void LSCSettings::writeString(string optionName, string optionValue, std::map<string, string> settingsMap)
{
    settingsMap[optionName] = optionValue;
    writeSettings(settingsMap);
}

void LSCSettings::writeString(string optionName, string optionValue)
{
    std::map<std::string,std::string> optionMap = getSettingsMap();
    writeString(optionName, optionValue, optionMap);
}

void LSCSettings::readSettings( BoostProgramOptions::options_description& desc, BoostProgramOptions::variables_map& vm ) {
    return readSettings(desc, vm, true);
}

void LSCSettings::readSettings( BoostProgramOptions::options_description& desc, BoostProgramOptions::variables_map& vm, bool allowUnregistered )
{
    std::ifstream settings_file( getSettingsFilePath() );

    // Clear the map.
    vm = BoostProgramOptions::variables_map();

    try {
        BoostProgramOptions::store( BoostProgramOptions::parse_config_file(settings_file, desc, true), vm );
    } catch(std::exception const&  ex) {
        LSCLang::printException(ex);
    }

    settings_file.close();
    BoostProgramOptions::notify( vm );
}


string LSCSettings::getSettingsFilePath() {
    return LSCPlatformTools::ensureConfigDir() + FILE_SEPARATOR + string("libsociopathy.ini");       
}

string LSCSettings::getString(std::string optionName)
{
    return getStringWithoutSchema(optionName);
}

string LSCSettings::getStringWithoutSchema(std::string optionName)
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

std::vector<string> LSCSettings::getSettingsNames()
{
    std::vector<std::string> optionNames;
    optionNames.push_back("backendType");

    //  return RECOGNIZED_OPTION_NAMES;
    return optionNames;
}

std::map<std::string, std::string> LSCSettings::getSettingsMap()
{
    BoostProgramOptions::options_description desc("Options");

    std::vector<string> optionNames = getSettingsNames();

    std::map<std::string,std::string> optionMap;

    std::for_each( optionNames.begin(), optionNames.end(), [&](string &elem){
        desc.add_options()(elem.c_str(), elem.c_str() );
    });

    BoostProgramOptions::variables_map vm;
    readSettings( desc, vm );

    for(BoostProgramOptions::variables_map::iterator it = vm.begin(); it != vm.end(); ++it) {
        BoostProgramOptions::variable_value variableValue = it->second;
        boost::any anyValue = variableValue.value();
        std::string stringValue =  boost::any_cast< std::string >(anyValue);
        optionMap[it->first] = stringValue;
    }

    return optionMap;
}

string LSCSettings::getStringWithSchema(std::string optionName)
{
    std::string optionValue;

    BoostProgramOptions::options_description desc("Options");


    desc.add_options()
            (optionName.c_str(), BoostProgramOptions::value< std::string >( &optionValue ), optionName.c_str() );


    BoostProgramOptions::variables_map vm;
    readSettings( desc, vm );

    return optionValue;
}
