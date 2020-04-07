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
    void recorrerInsertar(Nodo* nodo,Nodo* padre);
    virtual ~Arbol();
    Nodo *raiz;
    
private:

};

#endif /* ARBOL_H */

