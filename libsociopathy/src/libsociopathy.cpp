#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>

#include "LSCPlatformTools.h"
#include "LSCSettings.h"


#include "libsociopathy.h"

Libsociopathy::Libsociopathy()
{    
    std::cout << "CONSTRUCTOR STARTED" << std::endl;
    std::cout << "USER HOME: " << LSCPlatformTools::getUserHomeDir() << std::endl;

    std::string name;

    // Setup options.
    BoostProgramOptions::options_description desc("Options");
    desc.add_options()
            ("name", BoostProgramOptions::value< std::string >( &name ), "name" );
    BoostProgramOptions::variables_map vm;

    // Write, read, and print settings.
    LSCSettings::writeSettings( "test" );
    LSCSettings::readSettings( desc, vm );
    std::cout << "name = " << name << std::endl;

    // Write, read, and print newer settings.
    LSCSettings::writeSettings( "another test" );
    LSCSettings::readSettings( desc, vm );
    std::cout << "name = " << name << std::endl;
}


