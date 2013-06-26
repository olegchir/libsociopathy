#ifndef LIBSOCIOPATHY_H
#define LIBSOCIOPATHY_H

#include <iostream>
#include <string>
#include "libsociopathy_global.h"

#include <LSCBackend.h>

class LIBSOCIOPATHYSHARED_EXPORT Libsociopathy
{   
	LSCBackend* backend;
public:
    Libsociopathy();
	~Libsociopathy();
};

#endif // LIBSOCIOPATHY_H
