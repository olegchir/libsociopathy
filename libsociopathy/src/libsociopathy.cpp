#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>
#include <sqlite3.h>

#include "LSCPlatformTools.h"
#include "LSCSettings.h"

#include "LSCBackendSQLite.h"
#include "LSCBackend.h"

#include "libsociopathy.h"


Libsociopathy::Libsociopathy()
{    
	std::cout << "CONSTRUCTOR STARTED" << std::endl;
	std::cout << "USER HOME: " << LSCPlatformTools::getUserHomeDir() << std::endl;

	backend = NULL;

	map<string,string> settingsMap = LSCSettings::getSettingsMap();
	string backendType = settingsMap["backendType"];
	
	if (backendType.empty()) {
		settingsMap["backendType"] = backendType = "sqlite";
		LSCSettings::writeSettings(settingsMap);
	} 

	if (0==backendType.compare("sqlite")) {
		backend = new LSCBackendSQLite();
	} 
	else {
		std::cout << "Unknown backend" << std::endl;
		return;
	}

	try {
		string configDir = LSCPlatformTools::ensureConfigDir();
		std::cout << configDir << "\n";
	} catch (...) {
		std::cout << "Can't create config dir" << std::endl;
		return;
	}	

    
	backend->test();
	

	std::cout << "CONTRUCTOR STOPPED";
}

Libsociopathy::~Libsociopathy()
{
	delete backend;
}


