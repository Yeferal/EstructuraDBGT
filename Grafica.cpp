/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafica.cpp
 * Author: yefer
 * 
 * Created on 8 de abril de 2020, 10:32 PM
 */

#include "Grafica.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string> 
#include <vector>
#include <cstring>
#include <string.h>
#include <stdio.h>

#include <fstream>
using namespace std;

Grafica::Grafica() {
}

Grafica::Grafica(const Grafica& orig) {
}

void Grafica::graficarTabla(Tabla& ta) {
    code = "digraph G {\n";
    //code += ta.GetNombre()+"--->";
    int pos =1;
    while (ta.listaC->isTamanio(pos)) {
        cout<<"entroooo"<<endl;
        Columna &c = ta.listaC->buscar(pos);
        //if(c != NULL){
           code += ta.GetNombre()+"->"+c.GetTitulo()+";\n"; 
           code += c.GetTitulo()+"[ shape=square];";
        //}
           pos++;
    }

    code += ta.GetNombre()+"[ shape=square];";
    code += "}";
    abrirImagen("tabla");
}

void Grafica::graficarTablas(ListaTabla& lista) {
    
}



void Grafica::abrirImagen(string nombre) {
    ofstream archivo;
    string arcT = nombre+".dot";
    archivo.open(arcT.c_str(),ios::out);
        
    if(archivo.fail()){
        cout<<"NO se puede abrir"<<endl;
        exit(1);
    }else{
        cout<<"SI se puede abrir"<<endl;
    }
    archivo<<code;
    archivo.close();
    string coman = "dot -Tpng "+nombre+".dot -o "+nombre+".png";
    string com = "nohup display /home/yefer/NetBeansProjects/C++/EstructuraDB/"+nombre+".png";
    cout<<coman.c_str()<<endl;
    cout<<com.c_str()<<endl;
    system(coman.c_str());
    
    system(com.c_str());
}


Grafica::~Grafica() {
}

