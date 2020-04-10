

#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "Arbol.h"
#include "Nodo.h"

class TablaHash {
public:
    class NodoLista{
        
    public:
        NodoLista *anterio;
        NodoLista *siguiente;
        Arbol arbol;
        int posicion;
        NodoLista(Arbol &a){
            
            arbol = a;
        }
    };
    NodoLista* primero;
    NodoLista* ultimo;
    
public:
    TablaHash();
    TablaHash(const TablaHash& orig);
    void insertar(Arbol &arbol);
    Arbol& buscar(int);
    void actualizarArbol(Arbol &nuevoArbol,int);
    void insertarNodoArbol(Nodo *nodo,int posicion);
    void desplegarLista();
    bool isListaVacia();
    virtual ~TablaHash();
private:
    int tamanio;
};

#endif /* TABLAHASH_H */

