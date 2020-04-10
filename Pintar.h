/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pintar.h
 * Author: yefer
 *
 * Created on 9 de abril de 2020, 07:29 PM
 */

#ifndef PINTAR_H
#define PINTAR_H

#include "Tabla.h"
#include "ListaTupla.h"
#include "Nodo.h"

class Pintar {
public:
    Pintar();
    Pintar(const Pintar& orig);
    void pintarTodaTabla(Tabla &t);
    void recorreArbol(Nodo *padre,string col);
    virtual ~Pintar();
private:
    ListaTupla *listaTup = new ListaTupla();
};

#endif /* PINTAR_H */

