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
    
    archivo.open("Arch_LOG.dot",ios::out);
        
    if(archivo.fail()){
        cout<<"NO se puede abrir"<<endl;
        exit(1);
    }else{
        cout<<"SI se puede abrir"<<endl;
    }
    string code = "";
    archivo<<code;
    archivo.close();
}

ArchivoLog::ArchivoLog(const ArchivoLog& orig) {
}

ArchivoLog::~ArchivoLog() {
}

