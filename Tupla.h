

#ifndef TUPLA_H
#define TUPLA_H
#include "Nodo.h"


class Tupla {
public:
    Tupla();
    Tupla(const Tupla& orig);
    void insertar(string,int,string);
    void desplegarLista();
    Nodo& getTupla();
    Nodo* getNodoTupla(string);
    void modificar(string,int,string);
    bool isListaVacia();
    virtual ~Tupla();
    Nodo *primero;
    Nodo *ultimo;
private:
    int tamanio;
};

#endif /* TUPLA_H */

