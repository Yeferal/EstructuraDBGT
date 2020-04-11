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
            while(aux->registroIzquierda!=NULL){
                aux = aux->registroIzquierda;
            }
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

void ListaTupla::desplegarListaColumna(LIstaColumnas& lis) {
    NodoLista* actual;
    actual = primero;
    int numCol = 1;
    string nombreCol;
    
    if (!isListaVacia()) {
        
        while (actual!=NULL) {
            Nodo* aux = actual->registro;
            numCol = 1;
            while (lis.isTamanio(numCol)) {
                nombreCol = lis.buscar(numCol).GetTitulo();
                while(aux->registroIzquierda!=NULL){
                    aux = aux->registroIzquierda;
                }
                while(aux!=NULL){
                    if(aux->columna==nombreCol){
                        cout<<"|"<<aux->texto<<"\t"<<ends;
                        aux = aux->registroDerecha;
                        
                        break;
                    }
                    aux = aux->registroDerecha;
                    
                }
                numCol++;
            }
            cout<<"|"<<endl;
            for (int i = 0; i < lis.tamanio; i++) {
                cout<<"+-------"<<ends;

            }
            cout<<"+"<<endl;
            actual = actual->siguiente;
            //numCol = 1;
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

