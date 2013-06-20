#include <iostream>
#include "libsociopathy.h"
#include "PlatformTools.h"

Libsociopathy::Libsociopathy()
{    
    std::cout << "CONSTRUCTOR STARTED" << std::endl;
    std::cout << "USER HOME: " << PlatformTools::getUserHomeDir() << std::endl;
}

