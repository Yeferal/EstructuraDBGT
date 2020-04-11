

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
#include "ArchivoLog.h"

using namespace std;
ListaTabla* listaTablas = new ListaTabla();
string code;
ArchivoLog *log = new ArchivoLog();
Grafica *g = new Grafica();
Hash *h = new Hash();
Pintar *pin = new Pintar();
LIstaColumnas *listaCAux = new LIstaColumnas();

void createTable(string consulta [], int logitu){
    int longitu = logitu;
    int bandera = 2;
    
    string nombreTabla = consulta[bandera];
    if(!listaTablas->isExisteTabla(nombreTabla)){
        Tabla ta = Tabla(nombreTabla);
        bandera = 4;
        do{
            string campo = consulta[bandera];
            string tipoDato = consulta[bandera+1];

            int tipo=0;
            if(tipoDato=="String"){
                tipo = 4;
            }else if(tipoDato=="Int"){
                tipo = 1;
            }else if(tipoDato=="Double"){
                tipo = 2;
            }else if(tipoDato=="Char"){
                tipo = 3;
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
    }else{
        cout<<"Ya existe una tabla con el mismo nombre\n\n"<<endl;
    }
    
}

void selectTabla(string consulta [], int logitu){
    
    int longitu = logitu;
    
    int bandera = 1;
    
    int bandera2 = 0;
    
    int pesoT=0;
    
    string nombreTabla;
    
    cout<<consulta<<endl;
    bool salir = true;
     bool existe = false;
    
        if(consulta[bandera]=="*"){
            bandera = 3;
            
            nombreTabla = consulta[bandera];
            
            cout<<nombreTabla<<endl;
        }else{
            do{
                string nombreCol = consulta[bandera];
                Columna *c = new Columna(nombreCol,0);
                listaCAux->insertar(*c);

                if(consulta[bandera+1]=="FROM"){
                    salir = false;
                    bandera+= 2;
                    //bandera=longitu;
                }else{
                    bandera++;
                    //bandera2++;
                }
            }while(salir);
            nombreTabla = consulta[bandera];

        }
     
     if(listaTablas->isExisteTabla(nombreTabla)){
         
         Tabla &t = listaTablas->getTablaN(nombreTabla);
         
         
         if(longitu==4){
           
            pin->pintarTodaTabla(t);
        }else if(longitu==8) {
            
            string colum = consulta[longitu-3];
            string condicion = consulta[longitu-1];
            cout<<colum<<" = "<<condicion<<endl;
            pin->pintarTodaTablaFiltrada(t,colum,condicion);
        }else{
            //listaCAux->desplegarLista();
            if((bandera+1)==longitu){
                pin->pintarTabla(t,*listaCAux);
            }else{
                
                string colum = consulta[longitu-3];
                string condicion = consulta[longitu-1];
                cout<<colum<<" = "<<condicion<<endl;
                pin->pintarTablaFiltrada(t,*listaCAux,colum,condicion);
            }
            
        }
     }else{
         cout<<"LA TABLA NO EXISTE"<<endl;
     }


     listaCAux->~LIstaColumnas();
    
    
    
}

void insertTable(string consulta [], int logitu){
    
    int longitu = logitu;
    int bandera = 2;
    int bandera2 = 0;
    int pesoT=0;
    string nombreTabla = consulta[bandera];
    Tabla ta = listaTablas->getTablaN(nombreTabla);
    //ta.listaC->desplegarLista();
    
    if(listaTablas->isExisteTabla(nombreTabla)){
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
            if(listaC.buscarNombre(nombreCol).GetTipo()!=p){
                cout<<"Error en el dato"<<dato<<" no es el tipo de dato que se esperaba"<<endl;
                string accion;
                accion = "\nERROR DE DATO :=====> "+dato+" se esperaba un "+listaC.buscarNombre(nombreCol).GetTipoTexto();
                log->escribir(accion);
            }
            ta.tablaHash->insertarNodoArbol(tupla->getNodoTupla(nombreCol),p);

            if(consulta[bandera+1]==")"){
                bandera=longitu;
            }else{
                bandera++;
                bandera2++;
            }

        }while(bandera!=logitu);
    }else{
        cout<<"LA TABLA NO EXISTE"<<endl;
    }
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
//    for (int i = 0; i < tamanio; i++) {
//        cout<<tok[i]<<endl;
//
//    }
    

    string convertido = consulta;
    string accion;
    string primeraPalabra = tok[0];
    cout<<"======"<<primeraPalabra<<"======"<<endl;
    if(primeraPalabra=="CREATE"){
        
        accion = "\nCONSULTA :=====> "+convertido;
        log->escribir(accion);
        createTable(tok,tamanio);
            //cout<<"crear"<<endl;
    }else if(primeraPalabra=="SELECT"){
        
        accion = "\nCONSULTA :=====> "+convertido;
        log->escribir(accion);
        selectTabla(tok,tamanio);
            //cout<<"seleccionar"<<endl;
    }else if(primeraPalabra=="INSERT"){
        
        accion = "\nCONSULTA :=====> "+convertido;
        log->escribir(accion);
        insertTable(tok,tamanio);
            //cout<<"insertar"<<endl;
    }else{
        
        accion = "ERROR en la consulta :=====> "+convertido;
        log->escribir(accion);
            cout<<"NO es una consulta"<<endl;
    }
    //tok = (string)malloc(sizeof(string));
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
        cout<<"\nElige Opcion\n"<<endl;
        cin>>opcion;
        cout<<"\n"<<endl;
        switch(opcion){
            case 1:
                if (!listaTablas->isListaVacia()) {
                    listaTablas->getTotalDatosTodo();
                }else{
                    cout<<"La DB esta vacia"<<endl;
                }
                
                break;
            case 2:
                if(!listaTablas->isListaVacia()){
                    int op;
                    cout<<"Seleccione la tabla que desea"<<endl;
                    listaTablas->desplegarLista();
                    cin>>op;
                    if(listaTablas->isTamanio(op)){
                        listaTablas->getTotalDatosTabla(op);
                    }else{
                        cout<<"Opcion no valida"<<endl;
                    }
                    
                }else{
                    cout<<"La DB esta vacia"<<endl;
                }
                break;
            case 3:
                if(!listaTablas->isListaVacia()){
                    int op;
                    int op2;
                    cout<<"Seleccione la tabla que desea"<<endl;
                    listaTablas->desplegarLista();
                    cin>>op;
                    cout<<"\nSeleccione el Tipo de Dato"<<endl;
                    cout<<"1. Int"<<endl;
                    cout<<"2. Double"<<endl;
                    cout<<"3. String"<<endl;
                    cout<<"4. Char"<<endl;
                    cin>>op2;
                    cout<<"\n"<<endl;
                    if(listaTablas->isTamanio(op) && op2>=1 && op2<=4){
                        listaTablas->getTotalFilasDB(op,op2);
                    }else{
                        cout<<"Opcion no valida"<<endl;
                    }
                    
                }else{
                    cout<<"La DB esta vacia"<<endl;
                }
                break;
            case 4:
                if (!listaTablas->isListaVacia()) {
                    listaTablas->getTotalColumnasDB();
                }else{
                    cout<<"La DB esta vacia"<<endl;
                }
                break;
            case 5:
                cout<<"\n|===================================================================================================================================================================================================|\n"<<endl;
                cout<<log->leer()<<endl;
                cout<<"\n|===================================================================================================================================================================================================|\n\n"<<endl;
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
        cout<<"+====================  Graficas GuatemayaDB  =====================+"<<endl;
        cout<<"| 1.- Estructura de Datos de toda la DB                           |"<<endl;
        cout<<"+-----------------------------------------------------------------+"<<endl;
        cout<<"| 2.- Estructura de Datos por Tabla                               |"<<endl;
        cout<<"+----------------------------------------------------------- -----+"<<endl;
        cout<<"| 3.- Estructura de Datos por Tabla y sus Datos                   |"<<endl;
        cout<<"+-----------------------------------------------------------------+"<<endl;
        cout<<"| 4.- Regresar al Menu Principal                                  |"<<endl;
        cout<<"+=================================================================+"<<endl;
        
        cin>>opcion;
        switch(opcion){
            case 1:
                if(!listaTablas->isListaVacia()){
                    g->graficarTablas(*listaTablas);
                }else{
                    cout<<"La DB esta vacia"<<endl;
                }
                break;
            case 2:
                if(!listaTablas->isListaVacia()){
                    int op;
                    cout<<"Seleccione la tabla que desea"<<endl;
                    listaTablas->desplegarLista();
                    cin>>op;
                    if(listaTablas->isTamanio(op)){
                        g->graficarTabla(listaTablas->getTabla(op));
                    }else{
                        cout<<"Opcion no valida"<<endl;
                    }
                    //listaTablas->getTotalDatosTabla(op);
                    
                }else{
                    cout<<"La DB esta vacia"<<endl;
                }
                break;
            case 3:
                if(!listaTablas->isListaVacia()){
                    int op;
                    cout<<"Seleccione la tabla que desea"<<endl;
                    listaTablas->desplegarLista();
                    cin>>op;
                    if(listaTablas->isTamanio(op)){
                        g->graficarTablaDatos(listaTablas->getTabla(op));
                    }else{
                        cout<<"Opcion no valida"<<endl;
                    }
                    //listaTablas->getTotalDatosTabla(op);
                    
                }else{
                    cout<<"La DB esta vacia"<<endl;
                }
                break;
            case 4:
                salir = false;
                cout<<"\n\n\n"<<endl;
                break;
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
                menuGraficas();
                break;
            case 3:
                menuReportes();
                break;
            case 4:
                salir = false;
                break;
            default:
                cout<<"\n\n\n\nOPCION NO VALIDA"<<endl;
                
                break;
        }
    }

    
    
    listaCAux->~LIstaColumnas();
    listaTablas->~ListaTabla();
        
    
    return 0;
}

