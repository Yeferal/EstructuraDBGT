

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
#include "Grafica.h"
#include "Tupla.h"
#include "Pintar.h"

using namespace std;
ListaTabla* listaTablas = new ListaTabla();
string code;
Grafica *g = new Grafica();
Hash *h = new Hash();
Pintar *pin = new Pintar();

void createTable(string consulta [], int logitu){
    int longitu = logitu;
    int bandera = 2;
    
    string nombreTabla = consulta[bandera];
    Tabla ta = Tabla(nombreTabla);
    bandera = 4;
    do{
        string campo = consulta[bandera];
        string tipoDato = consulta[bandera+1];
        
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
        
        if(consulta[bandera+2]==")"){
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
    
    //g->graficarTabla(ta);
}

void selectTabla(string consulta [], int logitu){
    int longitu = logitu;
    int bandera = 1;
    int bandera2 = 0;
    int pesoT=0;
    string nombreTabla;
    Tabla t;
    
    bool salir = true;
    if(consulta[bandera]=="*"){
        
        bandera = 3;
        
        nombreTabla = consulta[bandera];

        cout<<nombreTabla<<endl;
        t = listaTablas->getTablaN(nombreTabla);
    }else{
        do{
//            string nombreCol = consulta[bandera];
//            string dato = consulta[bandera2];
//
//            pesoT = h->encontrarPeso(dato);
//
//            tupla->modificar(dato,pesoT,nombreCol);
//            int p = h->funcionHash(dato);
//            ta.tablaHash->insertarNodoArbol(tupla->getNodoTupla(nombreCol),p);

            if(consulta[bandera+1]=="FROM"){
                salir = false;
                //bandera=longitu;
            }else{
                bandera++;
                //bandera2++;
            }
        }while(salir);

    }
    
    
    if(longitu==4){
        cout<<"bien"<<endl;
        pin->pintarTodaTabla(t);
    }else{
        cout<<"mall"<<endl;
    }
    
    
    
}



void insertTable(string consulta [], int logitu){
    int longitu = logitu;
    int bandera = 2;
    int bandera2 = 0;
    int pesoT=0;
    string nombreTabla = consulta[bandera];
    Tabla ta = listaTablas->getTablaN(nombreTabla);
    //ta.listaC->desplegarLista();
    LIstaColumnas &listaC = *ta.listaC;
    Tupla *tupla = new Tupla();
    int pos = 1;
    while (listaC.isTamanio(pos)) {
        Columna &c = listaC.buscar(pos);
        tupla->insertar(" ",0,c.GetTitulo());
        pos++;
    }

    bandera = 4;
    if((longitu-9)<=0){
        bandera2 = 9-1;
    }else{
        bandera2 = longitu-(2+((longitu-9)/2));
    }
    
    do{
        string nombreCol = consulta[bandera];
        string dato = consulta[bandera2];
        
        pesoT = h->encontrarPeso(dato);
        
        tupla->modificar(dato,pesoT,nombreCol);
        int p = h->funcionHash(dato);
        ta.tablaHash->insertarNodoArbol(tupla->getNodoTupla(nombreCol),p);
        
        if(consulta[bandera+1]==")"){
            bandera=longitu;
        }else{
            bandera++;
            bandera2++;
        }
        
    }while(bandera!=logitu);
}

void generarSplit(char* consulta, int cantidad){
    
    int tamanio =0;
    
    char *tex = NULL;
    
    tex = new char[cantidad];
    
    strcpy(tex,consulta);
    
    int logituf = cantidad;

    char tex3 [logituf];
    
    strcpy(tex3,tex);
    char * pibote = strtok(tex," ,\n");
    
    while (pibote!=NULL) {
        tamanio++;
        pibote = strtok(NULL," ,\n");
        
    }
    
    string tok[tamanio];
    tamanio=0;
    pibote = strtok(tex3," ,\n");
    while (pibote!=NULL) {
        
        tok[tamanio] = pibote;
        tamanio++;
        pibote = strtok(NULL," ,\n");
        
    }
    
    

    
    string primeraPalabra = tok[0];
    cout<<"======"<<primeraPalabra<<"======"<<endl;
    if(primeraPalabra=="CREATE"){
        createTable(tok,tamanio);
            cout<<"crear"<<endl;
    }else if(primeraPalabra=="SELECT"){
        selectTabla(tok,tamanio);
            cout<<"seleccionar"<<endl;
    }else if(primeraPalabra=="INSERT"){
        insertTable(tok,tamanio);
            cout<<"insertar"<<endl;
    }else{
        
            cout<<"NO es una consulta"<<endl;
    }
}

void generarGrafico(Nodo * raiz){
    if(raiz->izquierda!=NULL){
        
        string al =std::to_string(raiz->alturaIzquierda);
        cout<<al<<endl;
        string altura = " [label=\""+al+"\"]";
        //altura="";
        code +=raiz->texto+" ->"+raiz->izquierda->texto+altura+";\n";
        generarGrafico(raiz->izquierda);
    }else{
//        string al =std::to_string(raiz->alturaIzquierda);
//        cout<<al<<endl;
//        string altura = " [label=\""+al+"\"]";
//        
//        code +=raiz->texto+" ->IZQ"+raiz->texto+altura+";\n";
    }
    
    if(raiz->derecha!=NULL){
        string al =std::to_string(raiz->alturaDerecha);
        
        string altura = " [label=\""+al+"\"]";
        //altura="";
        code +=raiz->texto+" ->"+raiz->derecha->texto+altura+";\n";
        generarGrafico(raiz->derecha);
    }else{
//        string al =std::to_string(raiz->alturaDerecha);
//        
//        string altura = " [label=\""+al+"\"]";
//        code +=raiz->texto+" ->DER"+raiz->texto+altura+";\n";
    }
//    string al =std::to_string(raiz->FE);
//        
//        string altura = " [label=\""+al+"\"]";
//    code +=raiz->texto+altura+";\n";
}

void menuReportes(){
    bool salir = true;
    string consulta;
    int opcion;
    
    while (salir) {
        cout<<"\n\n\n"<<endl;
        cout<<"|====================  Reportes GuatemayaDB  =====================|"<<endl;
        cout<<"| 1.- Cantidad de Datos de toda la DB                             |"<<endl;
        cout<<"|-----------------------------------------------------------------|"<<endl;
        cout<<"| 2.- Cantidad de Datos por Tabla                                 |"<<endl;
        cout<<"|-----------------------------------------------------------------|"<<endl;
        cout<<"| 3.- Cantidad de Filas de un mismo tipo de dato de una Tabla     |"<<endl;
        cout<<"|-----------------------------------------------------------------|"<<endl;
        cout<<"| 4.- Cantidad de Todas las columnas de todas las tablas de una DB|"<<endl;
        cout<<"|-----------------------------------------------------------------|"<<endl;
        cout<<"| 5.- Log DB                                                      |"<<endl;
        cout<<"|-----------------------------------------------------------------|"<<endl;
        cout<<"| 6.- Regresar al Menu Principal                                  |"<<endl;
        cout<<"|=================================================================|"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                salir = false;
                cout<<"\n\n\n"<<endl;
                break;
            default:
                cout<<"\n\n\n\nOPCION NO VALIDA"<<endl;
                opcion=1;
        }
    }

}

void menuGraficas(){
    bool salir = true;
    string consulta;
    int opcion;
    
    while (salir) {
        cout<<"\n\n\n"<<endl;
        cout<<"|====================  Graficas GuatemayaDB  =====================|"<<endl;
        cout<<"| 1.- Cantidad de Datos de toda la DB                             |"<<endl;
        cout<<"|-----------------------------------------------------------------|"<<endl;
        cout<<"| 2.- Cantidad de Datos por Tabla                                 |"<<endl;
        cout<<"|-----------------------------------------------------------------|"<<endl;
        cout<<"| 3.- Cantidad de Filas de un mismo tipo de dato de una Tabla     |"<<endl;
        cout<<"|=================================================================|"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                salir = false;
                cout<<"\n\n\n"<<endl;
                break;
            default:
                cout<<"\n\n\n\nOPCION NO VALIDA"<<endl;
                opcion=1;
        }
    }

}



int main(int argc, char** argv) {
    
    
    bool salir = true;
    string consulta;
    int opcion;
    int cantidad = 0;
    char *con = NULL;
    
    
    
    while (salir) {
        cout<<"|====================  Opciones GuatemayaDB  =====================|"<<endl;
        cout<<"| 1.- Consultas                                                   |"<<endl;
        cout<<"|-----------------------------------------------------------------|"<<endl;
        cout<<"| 2.- Graficas                                                    |"<<endl;
        cout<<"|-----------------------------------------------------------------|"<<endl;
        cout<<"| 3.- Reportes                                                    |"<<endl;
        cout<<"|-----------------------------------------------------------------|"<<endl;
        cout<<"| 4.- Salir                                                       |"<<endl;
        cout<<"|=================================================================|"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                //
                cout<<"\n\n\n\nEscribe la consulta"<<endl;
                cout<<endl;
                getline(cin,consulta,';');
                //cout<<consulta<<endl;
                cantidad = consulta.size();
                con = new char[cantidad];
                strcpy(con,consulta.c_str());
                
                
                generarSplit(con, cantidad);
                break;
            case 2:
                cout<<"\n\n\n\nEscribe la Grafica"<<endl;
                break;
            case 3:
                menuReportes();
                break;
            case 4:
                salir = false;
                break;
            default:
                cout<<"\n\n\n\nOPCION NO VALIDA"<<endl;
                opcion=1;
        }
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//    string texto;
//        cout<<"Escriba: "<<endl;
//    //cin>> texto;
//        generarSplit("hol");
//        
//        Arbol arbol = Arbol();
//        arbol.insertar("100",100,"c1");
//        arbol.insertar("39",39,"c2");
//        arbol.insertar("51",51,"c3");
//        arbol.insertar("105",105,"c1");
//        arbol.insertar("103",103,"c1");
//        arbol.insertar("72",72,"c4");
//        arbol.insertar("73",73,"c4");
//        arbol.insertar("45",45,"c1");
//        arbol.insertar("29",29,"c2");
//        arbol.insertar("53",53,"c4");
//        arbol.insertar("54",54,"c4");
//        arbol.insertar("52",52,"c4");
//        arbol.insertar("3",3,"c2");
//        arbol.insertar("0",0,"c3");
//        arbol.insertar("74",74,"c4");
//        
//        arbol.insertar("10",10,"c3");
//        arbol.insertar("5",5,"c3");
//        arbol.insertar("15",15,"c3");
//        arbol.insertar("20",20,"c4");
//        arbol.insertar("25",25,"c1");
//        arbol.insertar("4",4,"c3");
//        arbol.insertar("6",6,"c4");
//        arbol.insertar("2",2,"c1");
//        arbol.insertar("11",11,"c4");
//        arbol.insertar("9",9,"c4");
        
        
//        arbol.insertar("15",15,"c3");
//        arbol.insertar("5",5,"c3");
//        arbol.insertar("10",10,"c3");
        
//        arbol.insertar("30",30,"c3");
//        arbol.insertar("20",20,"c3");
//        arbol.insertar("40",40,"c3");
//        arbol.insertar("10",10,"c3");
//        arbol.insertar("25",25,"c3");        
 //       arbol.insertar("50",50,"c3");
//        arbol.insertar("45",45,"c3");
        
//        cout<<"pintando"<<endl;
//        //arbol.recorrer(arbol.raiz);
//        code = "digraph G {\n";
//        generarGrafico(arbol.raiz);
//        
//        code += "}";
//    
//        //File 
//        ofstream archivo;
//        
//        archivo.open("grafica.dot",ios::out);
//        
//        if(archivo.fail()){
//            cout<<"NO se puede abrir"<<endl;
//            exit(1);
//        }
//
//        archivo<<code;
//        archivo.close();
//        
//        
//        system("dot -Tpng grafica.dot -o grafia.png");
//        system("nohup display /home/yefer/NetBeansProjects/C++/EstructuraDB/grafia.png");
        
    
    return 0;
}

