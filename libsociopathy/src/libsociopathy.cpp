#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>
#include <sqlite3.h>

#include "LSCPlatformTools.h"
#include "LSCSettings.h"


#include "libsociopathy.h"

Libsociopathy::Libsociopathy()
{    
	std::cout << "CONSTRUCTOR STARTED" << std::endl;
	std::cout << "USER HOME: " << LSCPlatformTools::getUserHomeDir() << std::endl;

	map<string,string> settingsMap = LSCSettings::getSettingsMap();
	string backendType = settingsMap["backendType"];
	if (0==backendType.compare("sqlite")) {

	} 
	else if (backendType.empty()) {
		settingsMap["backendType"] = "sqlite";
		LSCSettings::writeSettings(settingsMap);
	} else {
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

	//const char* SQL = "CREATE TABLE IF NOT EXISTS foo(a,b,c); INSERT INTO FOO VALUES(1,2,3); INSERT INTO FOO SELECT * FROM FOO;";


	//char *err = 0;

	//else if (sqlite3_exec(db, SQL, 0, 0, &err))
	//{
	//	fprintf(stderr, "Error SQL: %sn", err);
	//	sqlite3_free(err);
	//}

	//sqlite3_close(db);

	std::cout << "CONTRUCTOR STOPPED";
}


