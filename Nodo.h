/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: yefer
 *
 * Created on 6 de abril de 2020, 06:32 PM
 */

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std;

class Nodo {
public:
    Nodo();
    Nodo(string,int,string);
    Nodo(int,string);
    Nodo(const Nodo& orig);
    virtual ~Nodo();

public:
    string texto;
    int peso;
    int FE;
    int alturaDerecha;
    int alturaIzquierda;
    int altura;
    int isRaiz;
    string columna;
    Nodo *registroIzquierda;
    Nodo *registroDerecha;
    Nodo *padre;
    Nodo *izquierda;
    Nodo *derecha;
private:
    
};

#endif /* NODO_H */

