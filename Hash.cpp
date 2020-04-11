

#include "Hash.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string> 
using namespace std;

Hash::Hash() {
}

int Hash::funcionHash(string &texto){
    int codigo;
    int tamanio = 0;
    int suma = 0;
    bool bolEntero = false;
    bool bolDecimal = false;
    bool bolCaracater = false;
    bool bolString = false;
    
    codigo = texto.at(0);

    if(codigo>=48 && codigo<=57){
        bolEntero = true;
        do{
            codigo = texto.at(tamanio);
            suma += codigo;
            if(codigo==46){
                if(bolDecimal){
                  bolString = true;  
                  bolDecimal = false;
                  bolEntero = false;
                  break;
                }else{
                    bolDecimal = true;
                    bolEntero = false;
                }
            }else{
                if(codigo<48 || codigo>57){
                  bolString = true;  
                  bolDecimal = false;
                  bolEntero = false;
                  break;
                }
            }
            
            tamanio++;
        }while(texto.size()!=tamanio);
        
    }else if((codigo<48 || codigo>57) && texto.size()==1){
        bolCaracater = true;
    }else{
        bolString = true;
    }
    
    if(bolEntero){
        return 1;
    }
    if(bolDecimal){
        return 2;
    }
    if(bolCaracater){
        return 3;
    }
    if(bolString){
        return 4;
    }
    return 5;
    
}

int Hash::encontrarPeso(string texto) {
    int codigo;
    int peso = 0;
    int tamanio = 0;
    int suma = 0;
    bool bolEntero = false;
    bool bolDecimal = false;
    bool bolCaracater = false;
    bool bolString = false;
    
    codigo = texto.at(0);

    if(codigo>=48 && codigo<=57){
        bolEntero = true;
        do{
            codigo = texto.at(tamanio);
            suma += codigo;
            if(codigo==46){
                if(bolDecimal){
                  bolString = true;  
                  bolDecimal = false;
                  bolEntero = false;
                  break;
                }else{
                    bolDecimal = true;
                    bolEntero = false;
                }
            }else{
                if(codigo<48 || codigo>57){
                  bolString = true;  
                  bolDecimal = false;
                  bolEntero = false;
                  break;
                }
            }
            
            tamanio++;
        }while(texto.size()!=tamanio);
        
    }else if(codigo<48 || codigo>57 && texto.size()==1){
        bolCaracater = true;
    }else{
        bolString = true;
    }
    
    
    suma=0;
    tamanio =0;
        do{
            codigo = texto.at(tamanio);
            suma += codigo;
            
            
            tamanio++;
        }while(texto.size()!=tamanio);
        
    
    if(bolEntero){
        
        peso = atoi(texto.c_str());
    }
    if(bolDecimal){
        
        peso = suma;
    }
    if(bolCaracater){
        
        peso = texto.at(0);
    }
    if(bolString){
        
        peso = suma;
    }
    
    return peso;
}


Hash::~Hash() {
}

