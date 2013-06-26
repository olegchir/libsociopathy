#include <iostream>
#include <string>

const char FILE_SEPARATOR =
#ifdef _WIN32
                            '\\';
#else
                            '/';
#endif

using namespace std;

class LSCPlatformTools
{
public:
    static string getUserHomeDir();
	static string getConfigDir();
	static string ensureConfigDir();
    static bool isWindows();
    static bool isWindows_Dynamic();
    static bool isWindows_Static();
};
