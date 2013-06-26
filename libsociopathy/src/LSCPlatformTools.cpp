#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <exception>
#include <boost/filesystem.hpp>

#include <LSCPlatformTools.h>

//Platform macros:
//http://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive
//http://sourceforge.net/p/predef/wiki/OperatingSystems/

#ifdef _WIN32
//define something for Windows
#else
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#endif

string LSCPlatformTools::getUserHomeDir() {
#ifdef _WIN32
    char* userProfile = getenv("USERPROFILE");
    if (NULL!=userProfile) {
        return string(userProfile);
    }

    char* homeDrive = getenv("HOMEDRIVE");
    char* homePath = getenv("HOMEPATH");

    if (NULL==homeDrive || NULL==homePath) {
        return NULL;
    }
    string homeDriveStr = string(homeDrive);
    string homePathStr = string(homePath);
    string concatPath = homeDriveStr+homePathStr;
    return concatPath;
#else
    /*
     *Note though that the getpwuid() man page has this caveat:
     *"An application that wants to determine its user's home directory should inspect
     *the value of HOME (rather than the value getpwuid(getuid())->pw_dir ) since this
     *allows the user to modify their notion of "the home directory" during a login session."
     *So, we should check $HOME first.
     */
    char* home = getenv("HOME");
    if (NULL!=home) {
        return string(home);
    }

    struct passwd* pw = getpwuid(getuid());
    if (NULL!=pw) {
        const char* homedir = pw->pw_dir;
        if (NULL!=homedir) {
            return string(homedir);
        }
    }

    return NULL;
#endif
}

bool LSCPlatformTools::isWindows() {
    return isWindows_Static();
}

bool LSCPlatformTools::isWindows_Dynamic() {
    char* winDir = getenv("windir");
    if (NULL==winDir) {
        return false;
    } else {
        return true;
    }
}

bool LSCPlatformTools::isWindows_Static() {
#ifdef _WIN32
    return true;
#else
    return false;
#endif
}

std::string LSCPlatformTools::getConfigDir()
{
	return getUserHomeDir() + FILE_SEPARATOR + string(".config") + FILE_SEPARATOR + string("libsociopathy");
}

std::string LSCPlatformTools::ensureConfigDir()
{
	string configDir = getConfigDir();
	
	bool result = true;
	if (!boost::filesystem::exists(configDir)) {
		result = boost::filesystem::create_directories(configDir);
	}
	
	if (!result) {
		throw runtime_error("can't create config dir");
	} 

	return configDir;
}

#undef _CRT_SECURE_NO_WARNINGS
