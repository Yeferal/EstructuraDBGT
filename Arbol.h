/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: yefer
 *
 * Created on 6 de abril de 2020, 06:33 PM
 */

#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <stdlib.h>
#include <string> 
#include "Nodo.h"

using namespace std;

class Arbol {
public:
    Arbol();
    Arbol(const Arbol& orig);
    void insertar(string,int,string);
    void insertarNodo(Nodo *nodo);
    void recorrerInsertar(Nodo* nodo,Nodo* padre);
    void balancear(Nodo *padre);
    void rotacionSimpleDerecha(Nodo *actual);
    void rotacionSimpleIzquierda(Nodo *actual);
    void rotacionDobleDerecha(Nodo *actual);
    void rotacionDobleIzquierda(Nodo *actual);
    void verificarAlturaDerecha(Nodo *padre);
    void verificarAlturaIzquierda(Nodo *padre);
    void recorrer(Nodo *padre);
    virtual ~Arbol();
    Nodo *raiz;
    Nodo *PadreAB, *sHijo, *predecesor, *abuelo, *hijoHijo;
private:

};

#endif /* ARBOL_H */

