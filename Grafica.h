/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafica.h
 * Author: yefer
 *
 * Created on 8 de abril de 2020, 10:32 PM
 */

#ifndef GRAFICA_H
#define GRAFICA_H

#include "ListaTabla.h"

using namespace std;

class Grafica {
public:
    Grafica();
    Grafica(const Grafica& orig);
    void graficarTablas(ListaTabla &lista);
    void graficarTabla(Tabla &ta);
    void abrirImagen(string nombre);
    virtual ~Grafica();
private:
    string code;
    
};

#endif /* GRAFICA_H */

