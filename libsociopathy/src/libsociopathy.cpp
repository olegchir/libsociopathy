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

    LSCSettings::writeString("name","testN");

     std::cout << "CONTRUCTOR STOPPED";
}


