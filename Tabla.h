/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tabla.h
 * Author: yefer
 *
 * Created on 6 de abril de 2020, 02:56 PM
 */

#ifndef TABLA_H
#define TABLA_H
#include <iostream>
#include <stdlib.h>
#include <string> 
#include "LIstaColumnas.h"

using namespace std;

class Tabla {
public:
    Tabla();
    Tabla(string);
    string GetNombre();
    virtual ~Tabla();
    LIstaColumnas *listaC;
private:
    string nombre;
    
};

#endif /* TABLA_H */

