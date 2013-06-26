#include <iostream>
#include <exception>
#include <string>

#include "LSCLang.h"

void LSCLang::printException(const std::exception &ex)
{
    std::cout << getExceptionMessage(ex);
}

std::string LSCLang::getExceptionMessage(const std::exception &ex)
{
    return std::string(ex.what()) + " (" + std::string(typeid(ex).name()) + std::string(")\n");
}

