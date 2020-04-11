/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TablaHash.cpp
 * Author: yefer
 * 
 * Created on 6 de abril de 2020, 06:30 PM
 */

#include "TablaHash.h"

TablaHash::TablaHash() {
    primero = NULL;
    Arbol *a1 = new Arbol();
    Arbol *a2 = new Arbol();
    Arbol *a3 = new Arbol();
    Arbol *a4 = new Arbol();
    Arbol *a5 = new Arbol();
    insertar(*a1);
    insertar(*a2);
    insertar(*a3);
    insertar(*a4);
    insertar(*a5);
}

TablaHash::TablaHash(const TablaHash& orig) {
}

void TablaHash::insertar(Arbol &arbol) {
    NodoLista* nuevo;
    nuevo = new NodoLista(arbol);
    
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

Arbol& TablaHash::buscar(int pos) {
    NodoLista* actual;
    actual = primero;

    if (!isListaVacia()) {
        
        while (actual!=NULL) {
            
            if(actual->posicion==pos){
                
                return actual->arbol;
            }else{
                actual = actual->siguiente; 
            }
            
        }
        
    }else{
        cout<<"Esta vacia"<<endl;
    }
}

void TablaHash::actualizarArbol(Arbol& nuevoArbol, int pos) {
    NodoLista* actual;
    actual = primero;

    if (!isListaVacia()) {
        
        while (actual!=NULL) {
            
            if(actual->posicion==pos){
                actual->arbol = nuevoArbol;
                break;
               
            }else{
                actual = actual->siguiente; 
            }
            
        }
        
    }else{
        cout<<"Esta vacia"<<endl;
    }
}




void TablaHash::desplegarLista() {
    NodoLista* actual;
    actual = primero;

    if (!isListaVacia()) {
        
        while (actual!=NULL) {
            Arbol &ar = actual->arbol;
            ar.recorrer(ar.raiz);
            actual = actual->siguiente;
        }
        
    }else{
        cout<<"Esta vacia"<<endl;
    }
}

void TablaHash::insertarNodoArbol(Nodo* nodo, int posicion) {
    NodoLista* actual;
    actual = primero;

    if (!isListaVacia()) {
        
        while (actual!=NULL) {
            
            if(actual->posicion==posicion){
                
                actual->arbol.insertarNodo(nodo);
                break;
            }
            actual = actual->siguiente; 
            
            
        }
        
    }
}



bool TablaHash::isListaVacia(){
    
    return primero == NULL;
}


TablaHash::~TablaHash() {
    
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

