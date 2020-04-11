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
    cout<<"numero de datos: "<<ar.cantidadDatos<<endl;
    recorreArbol(ar.raiz,columna);
    recorreArbol(t.tablaHash->primero->siguiente->arbol.raiz,columna);
    recorreArbol(t.tablaHash->primero->siguiente->siguiente->arbol.raiz,columna);
    recorreArbol(t.tablaHash->primero->siguiente->siguiente->siguiente->arbol.raiz,columna);
    t.listaC->desplegarLista();
    listaTup->desplegarLista();
    listaTup->~ListaTupla();
}

void Pintar::pintarTodaTablaFiltrada(Tabla& t, string titulo,string condicion) {
    cout<<"llego "<<endl;
    Columna &c = t.listaC->buscarNombre(titulo);
    cout<<"llego 1"<<endl;
    Arbol ar;
    switch(c.GetTipo()){
        case 1:
            ar = t.tablaHash->primero->arbol;
            break;
        case 2:
            ar = t.tablaHash->primero->siguiente->arbol;
            break;
        case 4:
            ar = t.tablaHash->primero->siguiente->siguiente->arbol;
            break;
        case 3:
            ar = t.tablaHash->primero->siguiente->siguiente->siguiente->arbol;
            break;
    }
    //cout<<"llego 2"<<endl;
    //string columna = t.listaC->primero->columna.GetTitulo();
    //cout<<"numero de datos: "<<ar.cantidadDatos<<endl;
    recorreArbolFiltrado(ar.raiz,titulo,condicion);
    
    cout<<"llego 3"<<endl;
    t.listaC->desplegarLista();
    listaTup->desplegarLista();
    listaTup->~ListaTupla();
}

void Pintar::pintarTabla(Tabla& t, LIstaColumnas& lisC) {
    Arbol &ar = t.tablaHash->primero->arbol;
    string columna = lisC.primero->columna.GetTitulo();
    //cout<<"coll: "<<columna<<endl;
    //cout<<"numero de datos: "<<ar.cantidadDatos<<endl;
    recorreArbol(ar.raiz,columna);
    recorreArbol(t.tablaHash->primero->siguiente->arbol.raiz,columna);
    recorreArbol(t.tablaHash->primero->siguiente->siguiente->arbol.raiz,columna);
    recorreArbol(t.tablaHash->primero->siguiente->siguiente->siguiente->arbol.raiz,columna);
    
    lisC.desplegarLista();
    if(lisC.isTamanio(1)){
        
        listaTup->desplegarListaColumna(lisC);
    }else{
        //filtrar ahora
    }
    listaTup->~ListaTupla();
}

void Pintar::pintarTablaFiltrada(Tabla& t, LIstaColumnas& lisC, string titulo,string condicion) {
    
    Columna &c = t.listaC->buscarNombre(titulo);
    
    Arbol ar;
    switch(c.GetTipo()){
        case 1:
            ar = t.tablaHash->primero->arbol;
            break;
        case 2:
            ar = t.tablaHash->primero->siguiente->arbol;
            break;
        case 4:
            ar = t.tablaHash->primero->siguiente->siguiente->arbol;
            break;
        case 3:
            ar = t.tablaHash->primero->siguiente->siguiente->siguiente->arbol;
            break;
    }
    recorreArbolFiltrado(ar.raiz,titulo,condicion);
    
    lisC.desplegarLista();
    if(lisC.isTamanio(1)){
        
        listaTup->desplegarListaColumna(lisC);
    }else{
        //filtrar ahora
    }
    listaTup->~ListaTupla();
}




void Pintar::recorreArbol(Nodo* padre, string col) {
    if(padre!=NULL){
        //cout<<"PADRE: "<<padre->texto<<" COLUMNA: "<<padre->columna<<endl;
        if(padre->izquierda==NULL){
            
        }else{
            recorreArbol(padre->izquierda,col);
        }
        if(padre->derecha==NULL){
            
        }else{
            recorreArbol(padre->derecha,col);
        }
        if(padre->columna==col){
            //cout<<"Agrego la tupla: "<<padre->texto<<endl;
            listaTup->insertar(padre);
        }else{
            //cout<<"NO Agrego la tupla: "<<padre->texto<<endl;
        }
    }
}
void Pintar::recorreArbolFiltrado(Nodo* padre, string col,string condicion) {
    if(padre!=NULL){
        cout<<"PADRE: "<<padre->texto<<endl;
        if(padre->izquierda==NULL){
            
        }else{
            recorreArbolFiltrado(padre->izquierda,col,condicion);
        }
        if(padre->derecha==NULL){
            
        }else{
            recorreArbolFiltrado(padre->derecha,col,condicion);
        }
        if(padre->columna==col && padre->texto==condicion){
            cout<<"Agrego la tupla: "<<padre->texto<<endl;
            listaTup->insertar(padre);
        }else{
            cout<<"NO Agrego la tupla: "<<padre->texto<<endl;
        }
    }
}



Pintar::~Pintar() {
}

