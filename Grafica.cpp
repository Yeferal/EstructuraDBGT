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

void Grafica::graficarTabla(Tabla& t) {
    code = "digraph G {\n";
    //code += ta.GetNombre()+"--->";
    int pos =1;
    code += "GuatemayaDB ->"+t.GetNombre()+";\n"; 
    while (t.listaC->isTamanio(pos)) {
        Columna &c = t.listaC->buscar(pos);
        code += "\""+t.GetNombre()+c.GetTitulo()+"\""+"[label=\""+c.GetTitulo()+"\"];\n";
           code += t.GetNombre()+"->"+t.GetNombre()+c.GetTitulo()+";\n"; 
           code += t.GetNombre()+c.GetTitulo()+"[ shape=square];\n";
           code += "node [shape=record];\n";
           code += "node"+t.GetNombre()+c.GetTitulo()+"[label = \"<f1> 0 | <f2> 1 | <f3> 2 | <f4> 3 |\"] \n";
           string indice = std::to_string(c.GetTipo());
           
           code += t.GetNombre()+c.GetTitulo() + " -> node"+t.GetNombre()+c.GetTitulo()+":f" + indice + ";\n";
           
           pos++;
    }
    code += "rankdir=LR;\n";
    code += t.GetNombre()+"[ shape=square];";
    code += "GuatemayaDB[ shape=square];";
    code += "}";
    abrirImagen("tabla");
}

void Grafica::graficarTablas(ListaTabla& lista) {
    code = "digraph G {\n";
    //code += ta.GetNombre()+"--->";
    int pos =1;
    int posL =1;
    
    while(lista.isTamanio(posL)){
        Tabla &t = lista.getTabla(posL);
        
        code += "GuatemayaDB ->"+t.GetNombre()+";\n"; 
        //code += "subgraph cluster_"+t.GetNombre()+"{\n";
        while (t.listaC->isTamanio(pos)) {
        
        Columna &c = t.listaC->buscar(pos);
           code += "\""+t.GetNombre()+c.GetTitulo()+"\""+"[label=\""+c.GetTitulo()+"\"];\n";
           code += t.GetNombre()+"->"+t.GetNombre()+c.GetTitulo()+";\n"; 
           code += t.GetNombre()+c.GetTitulo()+"[ shape=square];\n";
           code += "node [shape=record];\n";
           code += "node"+t.GetNombre()+c.GetTitulo()+"[label = \"<f1> 0 | <f2> 1 | <f3> 2 | <f4> 3 |\"] \n";
           string indice = std::to_string(c.GetTipo());
           
           code += t.GetNombre()+c.GetTitulo() + " -> node"+t.GetNombre()+c.GetTitulo()+":f" + indice + ";\n";
           
           pos++;
        }
        pos =1;
        posL++;
        code += t.GetNombre()+"[ shape=square];\n";
        //code += "}\n";
    }
    //code += "rankdir=LR;\n";
    //code += "DB[ shape=square];\n";
    code += "}";
    abrirImagen("tablas");
    
}

void Grafica::graficarTablaDatos(Tabla& ta) {
    code = "digraph G {\n";
    //code += ta.GetNombre()+"--->";
    int pos =1;
    code += "DB ->"+ta.GetNombre()+";\n"; 
    code += "node [shape=record];\n";
    code += "node0 [label = \"<f1> 0 | <f2> 1 | <f3> 2 | <f4> 3 |\"] \n";
    while (ta.listaC->isTamanio(pos)) {
        
        Columna &c = ta.listaC->buscar(pos);
        //if(c != NULL){
           code += ta.GetNombre()+"->"+c.GetTitulo()+";\n"; 
           code += c.GetTitulo()+"[ shape=square];\n";
           string indice = std::to_string(c.GetTipo());
           //code += c.GetTitulo()+" -> f"+indice+";\n";
           code += c.GetTitulo()+" -> node0:f"+indice+";\n";
        //"node0: "+
           pos++;
    }
    code += "node [shape = circle];";
    generarRaiz(ta.tablaHash->primero->arbol.raiz,1);
    generarRaiz(ta.tablaHash->primero->siguiente->arbol.raiz,2);
    generarRaiz(ta.tablaHash->primero->siguiente->siguiente->arbol.raiz,3);
    generarRaiz(ta.tablaHash->primero->siguiente->siguiente->siguiente->arbol.raiz,4);
    
    code += "rankdir=LR;\n";
    
    code += ta.GetNombre()+"[ shape=square];\n";
    code += "DB[ shape=square];\n";
    code += "}";
    
    abrirImagen("tablaDatos");
}

void Grafica::generarRaiz(Nodo *raiz, int indice) {
    if(raiz==NULL){
        
    }else{
        string in = std::to_string(indice);
        code += "node0: f"+in+" -> "+raiz->texto+";\n";
        
        recorrerArbol(raiz);
    }
}


void Grafica::recorrerArbol(Nodo* raiz) {
    if(raiz->izquierda!=NULL){
        
        string al =std::to_string(raiz->alturaIzquierda);
        cout<<al<<endl;
        string altura = " [label=\""+al+"\"]";
        altura="";
        code +=raiz->texto+" ->"+raiz->izquierda->texto+altura+";\n";
        recorrerArbol(raiz->izquierda);
    }else{
    }
    
    if(raiz->derecha!=NULL){
        string al =std::to_string(raiz->alturaDerecha);
        
        string altura = " [label=\""+al+"\"]";
        altura="";
        code +=raiz->texto+" ->"+raiz->derecha->texto+altura+";\n";
        recorrerArbol(raiz->derecha);
    }else{
    }

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

