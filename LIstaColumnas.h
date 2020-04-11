/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LIstaColumnas.h
 * Author: yefer
 *
 * Created on 6 de abril de 2020, 04:45 PM
 */

#ifndef LISTACOLUMNAS_H
#define LISTACOLUMNAS_H
#include "Columna.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class LIstaColumnas {
public:
    class NodoLista{
        
    public:
        NodoLista *anterio;
        NodoLista *siguiente;
        Columna columna;
        int posicion;
        NodoLista(Columna &c){
            
            columna = c;
        }
    };
    NodoLista* primero;
    NodoLista* ultimo;
    
public:
    LIstaColumnas();
    LIstaColumnas(const LIstaColumnas& orig);
    void insertar(Columna &columna);
    void quitarPrimero();
    void quitarUltimo();
    void quitarBloque(int numero);
    void borrarLista();
    void desplegarLista();
    Columna& buscar(int);
    Columna& buscarNombre(string);
    LIstaColumnas getListaTamanio(int numero);
    bool isTamanio(int numero);
    Columna &getPrimero();
    void getSiguiente(int numero);
    void getAnterior(int numero);
    Columna &getUltimo();
    bool isListaVacia();
    virtual ~LIstaColumnas();
    int tamanio;
private:
    

};

#endif /* LISTACOLUMNAS_H */

