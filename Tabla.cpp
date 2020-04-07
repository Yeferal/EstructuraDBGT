/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tabla.cpp
 * Author: yefer
 * 
 * Created on 6 de abril de 2020, 02:56 PM
 */

#include "Tabla.h"
#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std;

Tabla::Tabla() {
    
}

Tabla::Tabla(string nombre) {
    this->nombre = nombre;
    listaC = new LIstaColumnas;
}

string Tabla::GetNombre(){
    return nombre;
}

Tabla::~Tabla() {
}

