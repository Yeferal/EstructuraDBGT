/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: yefer
 * 
 * Created on 6 de abril de 2020, 06:33 PM
 */

#include "Arbol.h"
#include "Nodo.h"


Arbol::Arbol() {
    raiz = NULL;
    
}

Arbol::Arbol(const Arbol& orig) {
}

void Arbol::insertar(string texto, int peso, string columna){
    Nodo *nuevoNodo = new Nodo(texto,peso,columna);
    if(raiz==NULL){
        raiz = nuevoNodo;
    }else{
        recorrerInsertar(nuevoNodo,raiz);
    }
    
    
}

void Arbol::recorrerInsertar(Nodo* nodo, Nodo* padre){
    Nodo *temp=nodo;
    if(nodo->peso<padre->peso){
        if(padre->izquierda==NULL){
            padre->izquierda= temp;
            cout<<"Se inserto el nodo "<<padre->izquierda->texto<<endl;
        }else{
            recorrerInsertar(temp,padre->izquierda);
            
        }
    }else{
        if(padre->derecha==NULL){
            padre->derecha= temp;
            cout<<"Se inserto el nodo "<<padre->derecha->texto<<endl;
        }else{
            recorrerInsertar(temp,padre->derecha);
            
        }
    }
    
    
}

Arbol::~Arbol() {
}

