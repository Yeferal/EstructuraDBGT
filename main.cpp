

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

#include "ListaTabla.h"
#include "Tabla.h"
#include "Columna.h"
#include "Arbol.h"

using namespace std;
ListaTabla* listaTablas = new ListaTabla();
string code;



void createTable(string consulta [], int logitu){
    int longitu = logitu;
    int bandera = 2;
    
    string nombreTabla = consulta[bandera];
    Tabla ta = Tabla(nombreTabla);
    bandera = 4;
    do{
        string campo = consulta[bandera];
        string tipoDato = consulta[bandera+1];
        cout<<campo<<"--------"<<tipoDato<<endl;
        int tipo=0;
        if(tipoDato=="String"){
            tipo = 3;
        }else if(tipoDato=="Int"){
            tipo = 1;
        }else if(tipoDato=="Double"){
            tipo = 2;
        }else if(tipoDato=="Char"){
            tipo = 4;
        }
        
        Columna col = Columna(campo,tipo);
        col.SetTipoTexto(tipoDato);
        Columna &c = col;
        ta.listaC->insertar(c);
        
        if(consulta[bandera+2]==");"){
            bandera=longitu;
        }else{
            bandera = bandera+2;
        }
        cout<<bandera<<endl;
    }while(bandera!=logitu);
    
    
    ta.listaC->desplegarLista();
    
    Tabla &tabla = ta;
    listaTablas->insertar(tabla);
    listaTablas->desplegarLista();
}

void selectTabla(string *consulta){
    
}

void insertTable(string *consulta){
    
}

void generarSplit(char* consulta){
    
    int tamanio =0;
    
    char tex []= "CREATE TABLE tablaPrueba ( col1 Int , col2 String );";
    
    
    int logituf = sizeof(tex)/sizeof(tex[0]);
    char tex3 [logituf];
    cout<<"Longitud es: "<<logituf<<endl;
    strcpy(tex3,tex);
    char * pibote = strtok(tex," ,");
    
    while (pibote!=NULL) {
        tamanio++;
        pibote = strtok(NULL," ,");
        
    }
    
    string tok[tamanio];
    tamanio=0;
    pibote = strtok(tex3," ,");
    while (pibote!=NULL) {
        //cout<<pibote<<endl;
        tok[tamanio] = pibote;
        tamanio++;
        pibote = strtok(NULL," ,");
        
    }
    cout<<"tamanio: "<<tamanio<<endl;
    for (int i = 0; i < tamanio; i++) {
        cout<<tok[i]<<"-----------"<<(i+1)<<endl;
    }

    
    string primeraPalabra = tok[0];
    if(primeraPalabra=="CREATE"){
        createTable(tok,tamanio);
            cout<<"crear"<<endl;
    }else if(primeraPalabra=="SELECT"){
        //selectTabla(texto);
            cout<<"seleccionar"<<endl;
    }else if(primeraPalabra=="INSERT"){
        //insertTable(texto);
            cout<<"insertar"<<endl;
    }else{
        //insertTable(texto);
            cout<<"NO es una consulta"<<endl;
    }
}

void generarGrafico(Nodo * raiz){
    if(raiz->izquierda!=NULL){
        code +=raiz->texto+" ->"+raiz->izquierda->texto+";\n";
        generarGrafico(raiz->izquierda);
    }else{
        
    }
    
    if(raiz->derecha!=NULL){
        code +=raiz->texto+" ->"+raiz->derecha->texto+";\n";
        generarGrafico(raiz->derecha);
    }else{
        
    }
    
}


int main(int argc, char** argv) {
    
    string texto;
        cout<<"Escriba: "<<endl;
    //cin>> texto;
        
        
        Arbol arbol = Arbol();
        arbol.insertar("100",100,"c1");
        arbol.insertar("39",39,"c2");
        arbol.insertar("51",51,"c3");
        arbol.insertar("72",72,"c4");
        arbol.insertar("45",45,"c1");
        arbol.insertar("29",29,"c2");
        arbol.insertar("102",102,"c3");
        arbol.insertar("25",25,"c4");
        arbol.insertar("49",49,"c1");
        arbol.insertar("12",12,"c2");
        arbol.insertar("1",1,"c3");
        arbol.insertar("cc",53,"c4");
        arbol.insertar("c",54,"c4");
        arbol.insertar("a",52,"c4");
        arbol.insertar("3",3,"c2");
        arbol.insertar("0",0,"c3");
        
        
        
        code = "digraph G {\n";
        generarGrafico(arbol.raiz);
        
        code += "}";
    
        //File 
        ofstream archivo;
        
        archivo.open("grafica.dot",ios::out);
        
        if(archivo.fail()){
            cout<<"NO se puede abrir"<<endl;
            exit(1);
        }

        archivo<<code;
        archivo.close();
        
        
        system("dot -Tpng grafica.dot -o grafia.png");
        system("nohup display /home/yefer/NetBeansProjects/C++/EstructuraDB/grafia.png");
        
    
    return 0;
}

