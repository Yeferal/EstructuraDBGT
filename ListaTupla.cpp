/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaTupla.cpp
 * Author: yefer
 * 
 * Created on 9 de abril de 2020, 07:57 PM
 */

#include "ListaTupla.h"

ListaTupla::ListaTupla() {
    primero = NULL;
}

ListaTupla::ListaTupla(const ListaTupla& orig) {
}

void ListaTupla::insertar(Nodo* r) {
    NodoLista* nuevo;
    nuevo = new NodoLista(r);
    
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

void ListaTupla::desplegarLista() {
    NodoLista* actual;
    actual = primero;
    int numCol = 0;
    if (!isListaVacia()) {
        
        while (actual!=NULL) {
            Nodo* aux = actual->registro;
            numCol = 0;
            while(aux!=NULL){
                cout<<"|"<<aux->texto<<"\t"<<ends;
                aux = aux->registroDerecha;
                numCol++;
            }
            
            cout<<"|"<<endl;
            for (int i = 0; i < numCol; i++) {
                cout<<"+-------"<<ends;

            }
            cout<<"+"<<endl;
            
            actual = actual->siguiente;
        }
        cout<<""<<endl;
    }else{
        cout<<"La tabla es vacia"<<endl;
    }

}

bool ListaTupla::isListaVacia() {
    return primero == NULL;
}



ListaTupla::~ListaTupla() {
}

