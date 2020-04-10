/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pintar.cpp
 * Author: yefer
 * 
 * Created on 9 de abril de 2020, 07:29 PM
 */

#include "Pintar.h"

Pintar::Pintar() {
}

Pintar::Pintar(const Pintar& orig) {
}

void Pintar::pintarTodaTabla(Tabla& t) {
    Arbol &ar = t.tablaHash->primero->arbol;
    string columna = t.listaC->primero->columna.GetTitulo();
    cout<<"coll: "<<columna<<endl;
    recorreArbol(ar.raiz,columna);
//    recorreArbol(t.tablaHash->primero->siguiente->arbol.raiz,columna);
//    recorreArbol(ar.raiz,columna);
//    recorreArbol(ar.raiz,columna);

    t.listaC->desplegarLista();

    listaTup->desplegarLista();
    
}

void Pintar::recorreArbol(Nodo* padre, string col) {
    if(padre!=NULL){
        if(padre->izquierda==NULL){
            
        }else{
            recorreArbol(padre->izquierda,col);
        }
        if(padre->derecha!=NULL){
            
        }else{
            recorreArbol(padre->derecha,col);
        }
        if(padre->columna==col){
            cout<<"Agrego la tupla: "<<padre->texto<<endl;
            listaTup->insertar(padre);
        }
    }
}



Pintar::~Pintar() {
}

