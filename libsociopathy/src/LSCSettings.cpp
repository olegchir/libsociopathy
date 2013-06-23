#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>

#include "LSCPlatformTools.h"

#include "LSCSettings.h"



void LSCSettings::writeSettings( std::string value )
{
    std::ofstream settings_file( getSettingsFilePath() );
    settings_file << "name = " << value.c_str();
    settings_file.close();
}

void LSCSettings::readSettings( BoostProgramOptions::options_description& desc, BoostProgramOptions::variables_map& vm )
{
    std::ifstream settings_file( getSettingsFilePath() );

    // Clear the map.
    vm = BoostProgramOptions::variables_map();

    BoostProgramOptions::store( BoostProgramOptions::parse_config_file( settings_file , desc ), vm );
    settings_file.close();
    BoostProgramOptions::notify( vm );
}


string LSCSettings::getSettingsFilePath() {
    string fileName ("libsociopathy.ini");
    string homeDir = LSCPlatformTools::getUserHomeDir();
    string filePath (homeDir + FILE_SEPARATOR + fileName);
    return filePath;
}
