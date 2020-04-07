/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LIstaColumnas.cpp
 * Author: yefer
 * 
 * Created on 6 de abril de 2020, 04:45 PM
 */

#include "LIstaColumnas.h"
#include <iostream>
#include <stdlib.h>

LIstaColumnas::LIstaColumnas() {
    primero = NULL;
}

LIstaColumnas::LIstaColumnas(const LIstaColumnas& orig) {
}

void LIstaColumnas::insertar(Columna &columna){
    NodoLista* nuevo;
    nuevo = new NodoLista(columna);
    
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
LIstaColumnas LIstaColumnas::getListaTamanio(int numero){
    LIstaColumnas listaC = LIstaColumnas();
    NodoLista* actual;
    actual = primero;

    while (actual!=NULL) {
        if(actual->posicion>(tamanio-numero)){

            Columna &columna = actual->columna;
            listaC.insertar(columna);
        }
        actual = actual->siguiente;
    }
    cout<<"tamanioLIsta: "<<listaC.tamanio<<endl;
    return listaC;

}

void LIstaColumnas::quitarPrimero(){
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

void LIstaColumnas::quitarUltimo(){
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
void LIstaColumnas::quitarBloque(int numero){
    NodoLista* actual;
    actual = primero;
    for (int i = 0; i <numero; i++) {
        quitarUltimo();
    }
    cout<<"Quito"<<"_______"<<endl;
}

void LIstaColumnas::borrarLista(){
    
}
bool LIstaColumnas::isTamanio(int numero){
    cout<<tamanio<<"<="<<numero<<endl;
    if(numero<=tamanio){
        
        return true;
    }
    return false;
}


void LIstaColumnas::desplegarLista(){
    NodoLista* actual;
    actual = primero;

    if (!isListaVacia()) {
        
        while (actual!=NULL) {
            Columna &columna = actual->columna;
            cout<<actual->posicion<<".-    Columna: "<<columna.GetTitulo()<<",  Tipo:"<<columna.GetTipoTexto()<<endl;
            actual = actual->siguiente;
        }
        cout<<""<<endl;
        cout<<""<<endl;
    }else{
        cout<<"Esta vacia"<<endl;
    }

}
Columna& LIstaColumnas::getPrimero(){
    cout<<"Primero"<<"_______"<<endl;
    if (isListaVacia())
        throw "Cola vacía";
    
    cout<<"retorna Primero "<<endl;
    return primero->columna;
    
}
Columna& LIstaColumnas::getUltimo(){
    if (isListaVacia())
        throw "Cola vacía";
    return ultimo->columna;
}

bool LIstaColumnas::isListaVacia(){
    
    return primero == NULL;
}


void LIstaColumnas::getAnterior(int numero){
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
void LIstaColumnas::getSiguiente(int numero){
    NodoLista* actual;
    actual = primero;
    
    while (actual!=NULL) {
        if(actual->posicion==numero){
            if(actual->siguiente!=NULL){
                Columna &columna = actual->siguiente->columna;
                
                break;
            }else{
                cout<<"LA CARTA SIGUIENTE DE LA NUMERO "<<numero<<"NO EXISTE: "<<endl;
                break;
            }
        }
        actual = actual->siguiente;
    }
}

LIstaColumnas::~LIstaColumnas() {
    
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

