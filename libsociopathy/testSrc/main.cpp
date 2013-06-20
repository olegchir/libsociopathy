#include <iostream>
#include <libsociopathy.h>
using namespace std;
void main()
{
    Libsociopathy* ls = new Libsociopathy();
    cout << "TEST CLIENT STARTED" << endl;
    delete ls;
    fgetchar();
}
