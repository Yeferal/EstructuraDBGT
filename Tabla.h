

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
    int getTotalDatos();
    int getTotalFilas(int);
    void recorrerArbol(Nodo *padre, string columna);
//    int getTotalDatos();
    LIstaColumnas *listaC;
    TablaHash *tablaHash = new TablaHash();
    //Hash *funcionHash = new Hash();
    int filas;
private:
    string nombre;
    
};

#endif /* TABLA_H */

