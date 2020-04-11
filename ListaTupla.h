/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaTupla.h
 * Author: yefer
 *
 * Created on 9 de abril de 2020, 07:57 PM
 */

#ifndef LISTATUPLA_H
#define LISTATUPLA_H
#include "Nodo.h"
#include "Tupla.h"
#include "LIstaColumnas.h"

class ListaTupla {
public:
    class NodoLista{
        
    public:
        NodoLista *anterio;
        NodoLista *siguiente;
        Nodo* registro;
        int posicion;
        NodoLista(Nodo* r){
            
            registro = r;
        }
    };
    NodoLista* primero;
    NodoLista* ultimo;


public:
    ListaTupla();
    ListaTupla(const ListaTupla& orig);
    void insertar(Nodo* r);
    void desplegarLista();
    void desplegarListaColumna(LIstaColumnas &lis);
    bool isListaVacia();
    virtual ~ListaTupla();
private:
    int tamanio;
};

#endif /* LISTATUPLA_H */

