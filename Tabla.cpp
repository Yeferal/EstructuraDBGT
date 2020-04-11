

#include "Tabla.h"
#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std;

Tabla::Tabla() {
    
}

Tabla::Tabla(string nombre) {
    this->nombre = nombre;
    listaC = new LIstaColumnas;
}

string Tabla::GetNombre(){
    return nombre;
}

int Tabla::getTotalDatos() {
    int total = 0;
    total += tablaHash->primero->arbol.cantidadDatos;
    total += tablaHash->primero->siguiente->arbol.cantidadDatos;
    total += tablaHash->primero->siguiente->siguiente->arbol.cantidadDatos;
    total += tablaHash->primero->siguiente->siguiente->siguiente->arbol.cantidadDatos;
    return total;
}

int Tabla::getTotalFilas(int dato) {
    filas =0;
    
    switch(dato){
        case 1:
            if(tablaHash->primero->arbol.raiz!=NULL){
                recorrerArbol(tablaHash->primero->arbol.raiz, tablaHash->primero->arbol.raiz->columna);
            }
            
            break;
        case 2:
            if(tablaHash->primero->siguiente->arbol.raiz!=NULL){
                recorrerArbol(tablaHash->primero->siguiente->arbol.raiz, tablaHash->primero->arbol.raiz->columna);
            }
            break;
        case 3:
            if(tablaHash->primero->siguiente->siguiente->arbol.raiz!=NULL){
                recorrerArbol(tablaHash->primero->siguiente->siguiente->arbol.raiz, tablaHash->primero->arbol.raiz->columna);
            }
            break;
        case 4:
            if(tablaHash->primero->siguiente->siguiente->siguiente->arbol.raiz!=NULL){
                recorrerArbol(tablaHash->primero->siguiente->siguiente->siguiente->arbol.raiz, tablaHash->primero->arbol.raiz->columna);
            }
            break;
    }
    
    return filas;
}

void Tabla::recorrerArbol(Nodo* padre, string columna) {
    
    if(padre!=NULL){
        
        if(padre->izquierda==NULL){
            
        }else{
            recorrerArbol(padre->izquierda,columna);
        }
        if(padre->derecha==NULL){
            
        }else{
            recorrerArbol(padre->derecha,columna);
        }
        if(padre->columna==columna){
            
            filas++;
        }
    }
}




Tabla::~Tabla() {
    
}

