

#ifndef ARCHIVOLOG_H
#define ARCHIVOLOG_H
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string> 
#include <vector>
#include <cstring>
#include <string.h>
#include <stdio.h>

#include <fstream>
using namespace std;

class ArchivoLog {
public:
    ArchivoLog();
    ArchivoLog(const ArchivoLog& orig);
    string leer();
    void escribir(string);
    virtual ~ArchivoLog();
    //time_t now = time(0);
private:

};

#endif /* ARCHIVOLOG_H */

