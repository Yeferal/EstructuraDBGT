

#ifndef TABLA_H
#define TABLA_H
#include <iostream>
#include <stdlib.h>
#include <string> 
#include "LIstaColumnas.h"
#include "TablaHash.h"
#include "Hash.h"

using namespace std;

class Tabla {
public:
    Tabla();
    Tabla(string);
    string GetNombre();
    virtual ~Tabla();
    LIstaColumnas *listaC;
    TablaHash *tablaHash = new TablaHash();
    Hash *funcionHash = new Hash();
private:
    string nombre;
    
};

#endif /* TABLA_H */

