/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tupla.cpp
 * Author: yefer
 * 
 * Created on 8 de abril de 2020, 07:59 PM
 */

#include "Tupla.h"

Tupla::Tupla() {
}

Tupla::Tupla(const Tupla& orig) {
    primero = NULL;
}

void Tupla::insertar(string texto, int peso, string columna) {
    Nodo *nuevo = new Nodo(texto,peso,columna);
    if(primero == NULL){
        
        tamanio=1;
        primero = nuevo;
        primero->registroDerecha = NULL;
        primero->registroIzquierda = NULL;
        ultimo = primero;
    }else{
        tamanio++;
        
        ultimo->registroDerecha = nuevo;
        nuevo->registroDerecha=NULL;
        nuevo->registroIzquierda = ultimo;
        ultimo = nuevo;
    }
}

void Tupla::desplegarLista() {
    Nodo* actual;
    actual = primero;

    if (!isListaVacia()) {
        
        while (actual!=NULL) {
            cout<<"|"<<actual->texto<<"\t|"<<ends;
//            cout<<actual->peso<<".-    texto: "<<actual->texto<<",  Tipo:"<<actual->columna<<endl;
//            actual = actual->registroDerecha;
        }
        cout<<""<<endl;
    }else{
        cout<<"Esta vacia"<<endl;
    }
}

Nodo& Tupla::getTupla() {
    
    return *primero;
}

Nodo* Tupla::getNodoTupla(string columna) {
    Nodo* actual;
    actual = primero;
    if (!isListaVacia()) {
        
        while (actual!=NULL) {
            
            if(actual->columna==columna){
                
                return actual;
            }
            actual = actual->registroDerecha;
        }
    }
}


void Tupla::modificar(string texto, int peso, string columna) {
    Nodo* actual;
    actual = primero;

    if (!isListaVacia()) {
        
        while (actual!=NULL) {
            
            if(actual->columna==columna){
                actual->texto = texto;
                actual->peso = peso;
                break;
            }
            actual = actual->registroDerecha;
        }
        
    }
}


bool Tupla::isListaVacia() {
    
    return primero == NULL;
}




Tupla::~Tupla() {
}

