

#include "Hash.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string> 
using namespace std;

Hash::Hash() {
}

void Hash::funcionHash(string &texto){
    int codigo;
    int tamanio = 0;
    int suma = 0;
    bool bolEntero = false;
    bool bolDecimal = false;
    bool bolCaracater = false;
    bool bolString = false;
    
    codigo = texto.at(0);

    if(codigo>=49 && codigo<=57){
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
                if(codigo<49 || codigo>57){
                  bolString = true;  
                  bolDecimal = false;
                  bolEntero = false;
                  break;
                }
            }
            
            tamanio++;
        }while(texto.size()!=tamanio);
        
    }else if(codigo<49 || codigo>57 && texto.size()==1){
        bolCaracater = true;
    }else{
        bolString = true;
    }
    
    if(bolEntero){
        cout<<"Es un ENTERO"<<endl;
    }
    if(bolDecimal){
        cout<<"Es un DECIMAL"<<endl;
    }
    if(bolCaracater){
        cout<<"Es un CARACTER"<<endl;
    }
    if(bolString){
        cout<<"Es un STRING"<<endl;
    }
    
}

Hash::~Hash() {
}

