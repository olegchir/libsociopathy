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


    // Write, read, and print settings.
    LSCSettings::writeSettings( "name","test" );
    std::cout << "name = " << LSCSettings::getStringOption("name") << std::endl;

    // Write, read, and print newer settings.
    LSCSettings::writeSettings( "name","another test" );
    std::cout << "name = " << LSCSettings::getStringOption("name") << std::endl;

    LSCSettings::writeSettings( "name2","another test" );
    std::cout << "name = " << LSCSettings::getStringOption("name") << std::endl;
}


