#include <PlatformTools.h>
#include <iostream>

#ifdef _WIN32
//define something for Windows
#else
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#endif

string PlatformTools::getUserHomeDir() {
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

bool PlatformTools::isWindows() {
    char* winDir = getenv("windir");
    if (NULL==winDir) {
        return false;
    } else {
        return true;
    }
}
