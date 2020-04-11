/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArchivoLog.cpp
 * Author: yefer
 * 
 * Created on 11 de abril de 2020, 03:33 PM
 */

#include "ArchivoLog.h"


ArchivoLog::ArchivoLog() {
    ofstream archivo;
    
    archivo.open("Arch_LOG.txt",ios::out);
        
    if(archivo.fail()){
        cout<<"NO se puede abrir"<<endl;
        exit(1);
    }
    string code = "Inicia la base de datos de: GuatemayaDB.\n\n";
    archivo<<code;
    archivo.close();
}

ArchivoLog::ArchivoLog(const ArchivoLog& orig) {
}

string ArchivoLog::leer() {
    string lectura = "";
    string linea = "";
    ifstream archivo;
    archivo.open("Arch_LOG.txt",ios::in);
    if(archivo.fail()){
        cout<<"NO se puede abrir"<<endl;
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo,linea);
        lectura += linea+"\n";
    }
    archivo.close();
    
    return lectura;
}

void ArchivoLog::escribir(string accion) {
    string texto = leer();
    //tm *time = localeTime(&now);
    //texto += "\n"+;
    texto += "\n"+accion;
    
    ofstream archivo;
    
    archivo.open("Arch_LOG.txt",ios::out);
        
    if(archivo.fail()){
        cout<<"NO se puede abrir"<<endl;
        exit(1);
    }
    archivo<<texto;
    archivo.close();
    
}



ArchivoLog::~ArchivoLog() {
}

