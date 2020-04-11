

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

void ListaTabla::borrarLista(){
    
}
bool ListaTabla::isTamanio(int numero){
    //cout<<tamanio<<"<="<<numero<<endl;
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
            cout<<actual->posicion<<".  "<<"Nombre tabla: "<<tabla.GetNombre()<<endl;
            actual = actual->siguiente;
        }
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
            //cout<<"EXISTE LA TABLA"<<endl;
            return actual->tabla;
        }
        actual = actual->siguiente;
    }
}

bool ListaTabla::isExisteTabla(string nombre) {
    NodoLista* actual;
    actual = primero;
    
    while (actual!=NULL) {
        if(actual->tabla.GetNombre()==nombre){
            //cout<<"EXISTE LA TABLA"<<endl;
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void ListaTabla::getTotalDatosTodo() {
    NodoLista* actual;
    actual = primero;
    int total = 0;
    while (actual!=NULL) {
        total += actual->tabla.getTotalDatos();
        cout<<"Total de datos: "<<actual->tabla.GetNombre()<<"  No. "<<actual->tabla.getTotalDatos()<<endl;
        actual = actual->siguiente;
    }
    cout<<"\n\n===> Total de datos la DB: "<<total<<endl;
}


void ListaTabla::getTotalDatosTabla(int numero) {
    NodoLista* actual;
    actual = primero;
    
    while (actual!=NULL) {
        if(actual->posicion==numero){
            cout<<"Total de Datos de la DB: "<<actual->tabla.GetNombre()<<endl;
            cout<<"Datos: "<<actual->tabla.getTotalDatos()<<endl;
            break;
        }
        actual = actual->siguiente;
    }
}

void ListaTabla::getTotalColumnasDB() {
    NodoLista* actual;
    actual = primero;
    int total = 0;
    while (actual!=NULL) {
        total += actual->tabla.listaC->tamanio;
        cout<<"Total de Columnas: "<<actual->tabla.GetNombre()<<"  No. "<<actual->tabla.listaC->tamanio<<endl;
        actual = actual->siguiente;
    }
    cout<<"\n\n===> Total de Columnas la DB: "<<total<<endl;
}

void ListaTabla::getTotalFilasDB(int numero, int dato) {
    NodoLista* actual;
    actual = primero;
    
    while (actual!=NULL) {
        if(actual->posicion==numero){
            cout<<"Total de Filas de la tabla: "<<actual->tabla.GetNombre()<<endl;
            cout<<"Filas: "<<actual->tabla.getTotalFilas(dato)<<endl;
            break;
        }
        actual = actual->siguiente;
    }
}


bool ListaTabla::isListaVacia(){
    
    return primero == NULL;
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
            nodo->tabla.~Tabla();
            ultimo = ultimo->anterio;
            ultimo->siguiente = NULL;
            tamanio--;
            delete nodo;
        }
        }
        NodoLista* nodo = primero;
        nodo->tabla.~Tabla();
        primero=NULL;
        ultimo = NULL;
        delete nodo;
    }

}

