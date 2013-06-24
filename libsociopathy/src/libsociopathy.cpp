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

    const char* SQL = "CREATE TABLE IF NOT EXISTS foo(a,b,c); INSERT INTO FOO VALUES(1,2,3); INSERT INTO FOO SELECT * FROM FOO;";

    sqlite3 *db = 0;
	char *err = 0;

    if( sqlite3_open("my_cosy_database.dblite", &db) )
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));

	else if (sqlite3_exec(db, SQL, 0, 0, &err))
	{
        fprintf(stderr, "Error SQL: %sn", err);
		sqlite3_free(err);
	}

	sqlite3_close(db);

    std::cout << "CONTRUCTOR STOPPED";
}


