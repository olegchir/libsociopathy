#include <iostream>
#include <string>
#include <exception>

class LSCLang
{
public:
    static void printException(std::exception const&  ex);
    static std::string getExceptionMessage(std::exception const&  ex);
};
