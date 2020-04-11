
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
    void borrarLista();
    void desplegarLista();
    ListaTabla getListaTamanio(int numero);
    bool isTamanio(int numero);
    Tabla &getPrimero();
    Tabla &getUltimo();
    Tabla &getTabla(int numero);
    Tabla &getTablaN(string nombre);
    bool isExisteTabla(string nombre);
    bool isListaVacia();
    virtual ~ListaTabla();
    int totalDatos;
    void getTotalDatosTodo();
    void getTotalDatosTabla(int);
    void getTotalFilasDB(int,int);
    void getTotalColumnasDB();
private:
    int tamanio;

};

#endif /* LISTATABLA_H */

