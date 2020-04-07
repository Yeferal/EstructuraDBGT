/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Columna.h
 * Author: yefer
 *
 * Created on 5 de abril de 2020, 06:26 PM
 */

#ifndef COLUMNA_H
#define COLUMNA_H
#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std;

class Columna {
public:
    Columna();
    Columna(string, int);
    virtual ~Columna();
    string GetTitulo();
    int GetTipo();
    string GetTipoTexto();
    void SetTitulo(string titulo);
    void SetTipo(int tipo);
    void SetTipoTexto(string tipoTexto);
private:
    string titulo;
    int tipo;
    string tipoTexto;
};

#endif /* COLUMNA_H */

