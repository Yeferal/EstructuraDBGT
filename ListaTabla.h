
#ifndef LISTATABLA_H
#define LISTATABLA_H
    #include <iostream>
    #include <stdlib.h>
    #include "Tabla.h"

    using namespace std;

class ListaTabla {
    
public:
    class NodoLista{
        
    public:
        NodoLista *anterio;
        NodoLista *siguiente;
        Tabla tabla;
        int posicion;
        NodoLista(Tabla &t){
            
            tabla = t;
        }
    };
    NodoLista* primero;
    NodoLista* ultimo;
    
public:
    ListaTabla();
    ListaTabla(const ListaTabla& orig);
    void insertar(Tabla &tabla);
    void quitarPrimero();
    void quitarUltimo();
    void quitarBloque(int numero);
    void borrarLista();
    void desplegarLista();
    ListaTabla getListaTamanio(int numero);
    bool isTamanio(int numero);
    Tabla &getPrimero();
    void getSiguiente(int numero);
    void getAnterior(int numero);
    Tabla &getUltimo();
    Tabla &getTabla(int numero);
    Tabla &getTablaN(string nombre);
    bool isListaVacia();
    virtual ~ListaTabla();
private:
    int tamanio;

};

#endif /* LISTATABLA_H */

