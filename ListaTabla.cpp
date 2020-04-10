

#include "ListaTabla.h"
#include <iostream>
#include <stdlib.h>
#include "Tabla.h"
using namespace std;

ListaTabla::ListaTabla() {
    primero = NULL;
    
}
ListaTabla::ListaTabla(const ListaTabla& orig) {
    
}

void ListaTabla::insertar(Tabla &tabla){
    NodoLista* nuevo;
    nuevo = new NodoLista(tabla);
    
    if(primero == NULL){
        nuevo->posicion=1;
        tamanio=1;
        primero = nuevo;
        primero->siguiente = NULL;
        primero->anterio = NULL;
        ultimo = primero;
    }else{
        tamanio++;
        nuevo->posicion=tamanio;
        ultimo->siguiente = nuevo;
        nuevo->siguiente=NULL;
        nuevo->anterio = ultimo;
        ultimo = nuevo;
    }
    
}
ListaTabla ListaTabla::getListaTamanio(int numero){
    ListaTabla listaT = ListaTabla();
    NodoLista* actual;
    actual = primero;

    while (actual!=NULL) {
        if(actual->posicion>(tamanio-numero)){

            Tabla &tabla = actual->tabla;
            listaT.insertar(tabla);
        }
        actual = actual->siguiente;
    }
    cout<<"tamanioLIsta: "<<listaT.tamanio<<endl;
    return listaT;

}

void ListaTabla::quitarPrimero(){
    if (isListaVacia()) {
        throw "La lista esta vacia";
    }else if(primero==ultimo){
        primero = NULL;
        ultimo = NULL;
        tamanio=0;
    }else{
        
        NodoLista* nodo = primero;
        primero = primero->siguiente;
        primero->anterio = NULL;
        tamanio--;
        delete nodo;
    }
    
}

void ListaTabla::quitarUltimo(){
    if (isListaVacia()) {
        throw "La lista esta vacia";
    }else if(primero==ultimo){
        primero = NULL;
        ultimo = NULL;
        tamanio=0;
    }else{
        //Carta &aux = ultimo->carta;
        //aux.pintar();
        
        NodoLista* nodo = ultimo;
        ultimo = ultimo->anterio;
        ultimo->siguiente = NULL;
        
        tamanio--;
        delete nodo;
    }

}
void ListaTabla::quitarBloque(int numero){
    NodoLista* actual;
    actual = primero;
    for (int i = 0; i <numero; i++) {
        quitarUltimo();
    }
    cout<<"Quito"<<"_______"<<endl;
}

void ListaTabla::borrarLista(){
    
}
bool ListaTabla::isTamanio(int numero){
    cout<<tamanio<<"<="<<numero<<endl;
    if(numero<=tamanio){
        
        return true;
    }
    return false;
}


void ListaTabla::desplegarLista(){
    NodoLista* actual;
    actual = primero;

    if (!isListaVacia()) {
        
        while (actual!=NULL) {
            Tabla &tabla = actual->tabla;
            cout<<"NOmbre tabla: "<<tabla.GetNombre()<<endl;
            actual = actual->siguiente;
        }
        cout<<""<<endl;
        cout<<""<<endl;
    }else{
        cout<<"Esta vacia"<<endl;
    }

}
Tabla& ListaTabla::getPrimero(){
    cout<<"Primero"<<"_______"<<endl;
    if (isListaVacia())
        throw "Cola vacía";
    
    cout<<"retorna Primero "<<endl;
    return primero->tabla;
    
}
Tabla& ListaTabla::getUltimo(){
    if (isListaVacia())
        throw "Cola vacía";
    return ultimo->tabla;
}

Tabla& ListaTabla::getTabla(int numero) {
    NodoLista* actual;
    actual = primero;
    
    while (actual!=NULL) {
        if(actual->posicion==numero){
            return actual->tabla;
            
        }
        actual = actual->siguiente;
    }
}

Tabla& ListaTabla::getTablaN(string nombre) {
    NodoLista* actual;
    actual = primero;
    
    while (actual!=NULL) {
        if(actual->tabla.GetNombre()==nombre){
            cout<<"EXISTE LA TABLA"<<endl;
            return actual->tabla;
        }
        actual = actual->siguiente;
    }
}



bool ListaTabla::isListaVacia(){
    
    return primero == NULL;
}


void ListaTabla::getAnterior(int numero){
    NodoLista* actual;
    actual = primero;
    
    while (actual!=NULL) {
        if(actual->posicion==numero){
            if(actual->anterio!=NULL){
                break;
            }else{
                cout<<"LA CARTA ANTERIO DE LA NUMERO "<<numero<<"NO EXISTE: "<<endl;
                break;
            }
            
        }
        actual = actual->siguiente;
    }
    
}
void ListaTabla::getSiguiente(int numero){
    NodoLista* actual;
    actual = primero;
    
    while (actual!=NULL) {
        if(actual->posicion==numero){
            if(actual->siguiente!=NULL){
                Tabla &tabla = actual->siguiente->tabla;
                
                break;
            }else{
                cout<<"LA CARTA SIGUIENTE DE LA NUMERO "<<numero<<"NO EXISTE: "<<endl;
                break;
            }
        }
        actual = actual->siguiente;
    }
}

ListaTabla::~ListaTabla() {
    
    if(!isListaVacia()){
        while (!isListaVacia()) {
        if (isListaVacia()) {
            throw "La lista esta vacia";
        }else if(primero==ultimo){
            primero = NULL;
            ultimo = NULL;
            tamanio=0;
        }else{

            NodoLista* nodo = ultimo;
            ultimo = ultimo->anterio;
            ultimo->siguiente = NULL;
            tamanio--;
            delete nodo;
        }
        }
        NodoLista* nodo = primero;
        primero=NULL;
        ultimo = NULL;
        delete nodo;
    }

}

