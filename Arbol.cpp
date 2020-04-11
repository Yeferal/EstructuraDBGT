/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: yefer
 * 
 * Created on 6 de abril de 2020, 06:33 PM
 */

#include <stdlib.h>

#include "Arbol.h"
#include "Nodo.h"


Arbol::Arbol() {
    raiz = NULL;
    cantidadDatos = 0;
}

Arbol::Arbol(const Arbol& orig) {
}

void Arbol::insertar(string texto, int peso, string columna){
    Nodo *nuevoNodo = new Nodo(texto,peso,columna);
    if(raiz==NULL){
        nuevoNodo->alturaIzquierda=0;
        nuevoNodo->alturaIzquierda=0;
        nuevoNodo->isRaiz = 1;
        raiz = nuevoNodo;
        cantidadDatos = 1;
        cout<<"Se inserto la raiz "<<raiz->texto<<endl;
    }else{
        recorrerInsertar(nuevoNodo,raiz);
        //recorrer(raiz);
        balancear(raiz);
        //recorrer(raiz);
        cout<<"balanceo"<<endl;
        //recorrer(raiz);
    }
    
    
}

void Arbol::insertarNodo(Nodo* nodo) {
    Nodo *nuevoNodo = nodo;
    if(raiz==NULL){
        nuevoNodo->alturaIzquierda=0;
        nuevoNodo->alturaIzquierda=0;
        nuevoNodo->isRaiz = 1;
        raiz = nuevoNodo;
        cantidadDatos = 1;
        cout<<"Se inserto la raiz "<<raiz->texto<<endl;
    }else{
        recorrerInsertar(nuevoNodo,raiz);
        //recorrer(raiz);
        balancear(raiz);
        //recorrer(raiz);
        //cout<<"balanceo"<<endl;
        //recorrer(raiz);
    }
}


void Arbol::recorrerInsertar(Nodo* nodo, Nodo* padre){
    Nodo *temp=nodo;
    if(nodo->peso<padre->peso){
        if(padre->izquierda==NULL){
            //temp->padre=padre;
            temp->FE=0;
            temp->alturaIzquierda = 0;
            temp->alturaDerecha = 0;
            temp->padre = padre;
            temp->isRaiz = 0;
            padre->izquierda= temp;
            padre->alturaIzquierda =1;
            cantidadDatos++;
            cout<<"Se inserto el nodo "<<padre->izquierda->texto<<endl;
        }else{
            recorrerInsertar(temp,padre->izquierda);
            verificarAlturaIzquierda(padre);
        }
    }else{
        if(padre->derecha==NULL){
            //temp->padre=padre;
            temp->FE=0;
            temp->alturaIzquierda = 0;
            temp->alturaDerecha = 0;
            temp->padre = padre;
            temp->isRaiz = 0;
            padre->derecha= temp;
            padre->alturaDerecha=1;
            cantidadDatos++;
            cout<<"Se inserto el nodo "<<padre->derecha->texto<<endl;
            
        }else{
            recorrerInsertar(temp,padre->derecha);
            verificarAlturaDerecha(padre);
            
            
        }
    }
    padre->FE = padre->alturaDerecha-padre->alturaIzquierda;
    
}

void Arbol::verificarAlturaIzquierda(Nodo *padre){
    if(padre!=NULL){
        //cout<<"CALCULA ALTURA"<<endl;
        if(padre->izquierda->alturaIzquierda>padre->izquierda->alturaDerecha){
            padre->alturaIzquierda = padre->izquierda->alturaIzquierda+1;
        }else{
            padre->alturaIzquierda = padre->izquierda->alturaDerecha+1;
        }
        //cout<<"TERMINA ALTURA"<<endl;
    }
    
    
}


void Arbol::verificarAlturaDerecha(Nodo *padre){
    if(padre!=NULL){
        //cout<<"CALCULA ALTURA"<<endl;
        if(padre->derecha->alturaIzquierda>padre->derecha->alturaDerecha){
            padre->alturaDerecha = padre->derecha->alturaIzquierda+1;
        }else{
            padre->alturaDerecha = padre->derecha->alturaDerecha+1;
        }
        //cout<<"TERMINA ALTURA"<<endl;
    }
    
    
}

void Arbol::rotacionSimpleDerecha(Nodo* actual){
    
    if(PadreAB==raiz){
        //cout<<" es UNA raiz"<<endl;
		raiz=sHijo;
		
		hijoHijo=sHijo->izquierda;
		
                
                PadreAB->izquierda = sHijo->derecha;
		sHijo->derecha=PadreAB;
		//PadreAB->izquierda=NULL;
		PadreAB->padre=sHijo;
		
		sHijo->padre=NULL;
		
                
		//PadreAB->dere=hijoHijo;
		//hijoHijo->padre=PadreAB;
		
		//sHijo->dere=PadreAB;
		
		
	}else{
        //cout<<"roto y no es raiz"<<endl;
		abuelo=PadreAB->padre;
                
                if(abuelo->derecha==PadreAB){
                    abuelo->derecha=PadreAB->izquierda;
                }else{
                    abuelo->izquierda=PadreAB->izquierda;
                }
                
                if(PadreAB->derecha!=NULL){
                   PadreAB->izquierda=sHijo->derecha;
                }else{
                   PadreAB->izquierda=NULL; 
                }
		
		sHijo->padre=abuelo;
		sHijo->derecha=PadreAB;
		PadreAB->padre=sHijo;
		//PadreAB->izquierda=NULL;
                
	}  
}

void Arbol::rotacionSimpleIzquierda(Nodo* actual){
    
    
    if (PadreAB==raiz){
        //cout<<" es UNA raiz"<<endl;
		raiz=sHijo;
		
		//sHijo->dere=hijoHijo;
		//hijoHijo->padre=sHijo;
		//hijoHijo->dere=NULL;
                //cout<<"Hijo: "<<sHijo->texto<<endl;
                //cout<<"HijoHijo: "<<hijoHijo->texto<<endl;
                //cout<<"Padre: "<<PadreAB->texto<<endl;
		
		sHijo->izquierda=PadreAB;
		PadreAB->padre=sHijo;
		PadreAB->derecha=NULL;
		
		sHijo->padre=NULL;
		
	}else{
        //cout<<"roto y no es raiz"<<endl;
		abuelo=PadreAB->padre;
                
                if(abuelo->izquierda==PadreAB){
                    abuelo->izquierda=PadreAB->derecha;
                }else{
                    abuelo->derecha=PadreAB->derecha;
                }
                
                if(PadreAB->izquierda!=NULL){
                   PadreAB->derecha=sHijo->izquierda;
                }else{
                   PadreAB->derecha=NULL; 
                }
                
		//abuelo->derecha=PadreAB->derecha;
                
		sHijo->padre=abuelo;
		sHijo->izquierda=PadreAB;
		PadreAB->padre=sHijo;
		//PadreAB->derecha=NULL;
	}
}

void Arbol::rotacionDobleDerecha(Nodo* actual){
    
    if (PadreAB==raiz){
		//cout<<" es UNA raiz"<<endl;
//		hijoHijo=sHijo->izquierda; //Ubico al hijo del hijo...
//		
//		raiz=hijoHijo; //Cambiar el apuntador de la raíz.
//		
//		hijoHijo->padre=NULL; //Aseguro que el padre de la raíz se quede en NULL
//		
//		hijoHijo->derecha=sHijo; // el nuevo padre debe apuntar al hijo izquierdo.		
//		sHijo->padre=hijoHijo; //El hijo debe apuntar a su nuevo padre.
//		if(sHijo->izquierda!=NULL){
//			sHijo->izquierda=hijoHijo->izquierda;
//		}else{
//			sHijo->izquierda=NULL; //Apuntar a Null la parte izquierda del hijo, ya que ahora no tendrá hijos...			
//		}
//		
//		//sHijo->dere=NULL; // Apuntar a Null la parte derecha del hijo, ya que ahora no tendrá Hijos...
//		
//		hijoHijo->izquierda=PadreAB; //El nuevo padre debe apuntar al hijo derecho.
//		
//		if(PadreAB->izquierda==NULL){
//			PadreAB->izquierda=NULL; //El antiguo padre debe apuntar ahora a nu
//		}
//
//		PadreAB->derecha=NULL; //el antiguo padre debe apuntar ahora a null
//		PadreAB->padre=hijoHijo; //Apuntar al nuevo padre ...
                
                
                
                
                
                //cout<<" es UNA raiz"<<endl;
		hijoHijo=sHijo->izquierda; //Ubico al hijo del hijo...
		//abuelo = raiz;
		raiz=hijoHijo; //Cambiar el apuntador de la raíz.
		
		hijoHijo->padre=NULL; //Aseguro que el padre de la raíz se quede en NULL
		
		hijoHijo->derecha=sHijo; // el nuevo padre debe apuntar al hijo izquierdo.		
		sHijo->padre=hijoHijo; //El hijo debe apuntar a su nuevo padre.
		
		//PadreAB->derecha=hijoHijo->izquierda; //Apuntar a Null la parte izquierda del hijo, ya que ahora no tendrá hijos...			
                sHijo->izquierda=NULL; 
                //cout<<"Hijo: "<<sHijo->texto<<endl;
                //cout<<"HijoHijo: "<<hijoHijo->texto<<endl;
                //cout<<"Padre: "<<PadreAB->texto<<endl;
                
		PadreAB->derecha=hijoHijo->izquierda; //El antiguo padre debe apuntar ahora a null 
		
		hijoHijo->izquierda=PadreAB; //El nuevo padre debe apuntar al hijo derecho.
		
		
		if(PadreAB->izquierda==NULL){
			PadreAB->izquierda=NULL; //El antiguo padre debe apuntar ahora a nu
		}
		PadreAB->padre=hijoHijo; //Apuntar al nuevo padre ...
                
                
                
	}else{
		//cout<<"roto y no es raiz"<<endl;
		abuelo=PadreAB->padre;
		
		hijoHijo=sHijo->izquierda; //Ubico al hijo del hijo...
		
		hijoHijo->padre=abuelo; //Aseguro que el padre de la raíz se quede apuntando al abuelo
		
                
                if(abuelo->izquierda==PadreAB){
                    abuelo->izquierda=hijoHijo;
                }else{
                    abuelo->derecha=hijoHijo;
                }
                
		hijoHijo->derecha=sHijo; // el nuevo padre debe apuntar al hijo izquierdo.		
		sHijo->padre=hijoHijo; //El hijo debe apuntar a su nuevo padre.
		
		sHijo->izquierda = NULL; 
                
                
//                if(sHijo->izquierda!=NULL){
//			sHijo->izquierda=hijoHijo->izquierda;
//		}else{
//			sHijo->izquierda=NULL; //Apuntar a Null la parte izquierda del hijo, ya que ahora no tendrá hijos...			
//		}
//		
//		//sHijo->dere=NULL; // Apuntar a Null la parte derecha del hijo, ya que ahora no tendrá Hijos...
//		
//		hijoHijo->izquierda=PadreAB; //El nuevo padre debe apuntar al hijo derecho.
//		
//		if(PadreAB->izquierda==NULL){
//			PadreAB->izquierda=NULL; //El antiguo padre debe apuntar ahora a nu
//		}
//		
//		PadreAB->derecha=NULL; //el antiguo padre debe apuntar ahora a null
//		PadreAB->padre=hijoHijo; //Apuntar al nuevo padre ...
//		
//                
//                //abuelo->izquierda=abuelo->derecha;
//		abuelo->derecha=hijoHijo;
                
                
                
                
                hijoHijo->izquierda=PadreAB; //El nuevo padre debe apuntar al hijo derecho.
		
		PadreAB->derecha=NULL; //El antiguo padre debe apuntar ahora a null 
		
		if(PadreAB->izquierda==NULL){
			PadreAB->izquierda=NULL; //El antiguo padre debe apuntar ahora a nu
		}
		PadreAB->padre=hijoHijo; //Apuntar al nuevo padre ...
                
                
                
                
                
                
                
	}
 
}

void Arbol::rotacionDobleIzquierda(Nodo* actual){
    if (PadreAB==raiz){
//		cout<<" es UNA raiz"<<endl;
//		hijoHijo=sHijo->derecha; //Ubico al hijo del hijo...
////		cout<<"Hijo: "<<sHijo->texto<<endl;
////                cout<<"HijoHijo: "<<hijoHijo->texto<<endl;
////                cout<<"Padre: "<<PadreAB->texto<<endl;
//                //cout<<"Hijo izquierda: "<<hijoHijo->derecha->texto<<endl;
//                if(hijoHijo->izquierda!=NULL){
//                    //cout<<"Hijo izquierda: "<<hijoHijo->izquierda->texto<<endl;
//                    abuelo=hijoHijo->izquierda;
//                }
//		raiz=hijoHijo; //Cambiar el apuntador de la raíz.
//		
//		hijoHijo->padre=NULL; //Aseguro que el padre de la raíz se quede en NULL
//		
//		hijoHijo->izquierda=sHijo; // el nuevo padre debe apuntar al hijo izquierdo.		
//		
//                //cout<<"Hijo izquierda: "<<hijoHijo->izquierda->izquierda->texto<<endl;
//                sHijo->padre=hijoHijo; //El hijo debe apuntar a su nuevo padre.
//		
//		sHijo->derecha=NULL; //Apuntar a Null la parte izquierda del hijo, ya que ahora no tendrá hijos...			
//                //sHijo->derecha=abuelo;
//                if(abuelo!=NULL){
//                    //cout<<"Hijo izquierda: "<<abuelo->texto<<endl;
//                    sHijo->derecha=abuelo;
//                    abuelo = NULL;
//                }
//                
//		//PadreAB->izquierda=NULL; //El antiguo padre debe apuntar ahora a null 
//		PadreAB->izquierda=hijoHijo->derecha;
//		hijoHijo->derecha=PadreAB; //El nuevo padre debe apuntar al hijo derecho.
//		
//		
//		if(PadreAB->derecha==NULL){
//			PadreAB->derecha=NULL; //El antiguo padre debe apuntar ahora a nu
//		}
//		PadreAB->padre=hijoHijo; //Apuntar al nuevo padre ...
        
        
                //cout<<" es UNA raiz"<<endl;
		hijoHijo=sHijo->derecha; //Ubico al hijo del hijo...
		//abuelo = raiz;
		raiz=hijoHijo; //Cambiar el apuntador de la raíz.
		
		hijoHijo->padre=NULL; //Aseguro que el padre de la raíz se quede en NULL
		
		hijoHijo->izquierda=sHijo; // el nuevo padre debe apuntar al hijo izquierdo.		
		sHijo->padre=hijoHijo; //El hijo debe apuntar a su nuevo padre.
		
		//PadreAB->derecha=hijoHijo->izquierda; //Apuntar a Null la parte izquierda del hijo, ya que ahora no tendrá hijos...			
                sHijo->derecha=NULL; 
                //cout<<"Hijo: "<<sHijo->texto<<endl;
                //cout<<"HijoHijo: "<<hijoHijo->texto<<endl;
                //cout<<"Padre: "<<PadreAB->texto<<endl;
                
		PadreAB->izquierda=hijoHijo->derecha; //El antiguo padre debe apuntar ahora a null 
		
		hijoHijo->derecha=PadreAB; //El nuevo padre debe apuntar al hijo derecho.
		
		
		if(PadreAB->derecha==NULL){
			PadreAB->derecha=NULL; //El antiguo padre debe apuntar ahora a nu
		}
		PadreAB->padre=hijoHijo; //Apuntar al nuevo padre ...
                //cout<<"Termino de rotar DOBLE IZQUIERDA"<<endl;
	}else{
        //cout<<"roto y no es raiz"<<endl;
		abuelo=PadreAB->padre;
                cout<<abuelo->texto<<endl;
                
		hijoHijo=sHijo->derecha; //Ubico al hijo del hijo...
		
		hijoHijo->padre=abuelo; //Aseguro que el padre de la raíz se quede apuntando al abuelo
		
                
                if(abuelo->derecha==PadreAB){
                    abuelo->derecha=hijoHijo;
                }else{
                    abuelo->izquierda=hijoHijo;
                }
		
		hijoHijo->izquierda=sHijo; // el nuevo padre debe apuntar al hijo izquierdo.		
		sHijo->padre=hijoHijo; //El hijo debe apuntar a su nuevo padre.
				
		sHijo->derecha=NULL; //Apuntar a Null la parte izquierda del hijo, ya que ahora no tendrá hijos...			
		
		
		hijoHijo->derecha=PadreAB; //El nuevo padre debe apuntar al hijo derecho.
		
		PadreAB->izquierda=NULL; //El antiguo padre debe apuntar ahora a null 
		
		if(PadreAB->derecha==NULL){
			PadreAB->derecha=NULL; //El antiguo padre debe apuntar ahora a nu
		}
		PadreAB->padre=hijoHijo; //Apuntar al nuevo padre ...
                
	}  
}

void Arbol::balancear(Nodo* padre) {
    
    if(padre!=NULL){
        
        balancear(padre->izquierda);
        //recorrer(padre);
        balancear(padre->derecha);
                
        //recorrer(padre);
        if((padre->FE==2) || (padre->FE==-2)){
            //cout<<"====================================================================="<<endl;
            
            PadreAB = padre;
            sHijo = padre->derecha;
            //cout<<" Padre: "<<padre->texto<<endl;
            if((PadreAB->FE>1) && (sHijo->FE>0)){
               // cout<<"Rotacion simple a la izquierda"<<endl;
                //cout<<" Padre: "<<padre->texto<<" Hijo: "<<padre->derecha->texto<<endl;
                //cout<<"PADRE  FE: "<<padre->FE<<"  HIjo  FE: "<<padre->derecha->FE<<endl;
                rotacionSimpleIzquierda(padre);
                recorrer(raiz);
                                
            }else if((PadreAB->FE>1) && (sHijo->FE<0)){
                //cout<<"Rotacion doble a la derecha."<<endl;
                //cout<<" Padre: "<<padre->texto<<" Hijo: "<<padre->derecha->texto<<endl;
                rotacionDobleDerecha(padre);
                recorrer(raiz);
                     
            }else{
                
                PadreAB = padre;
                sHijo = padre->izquierda;
                //cout<<"PADRE  FE: "<<padre->FE<<"  HIjo  FE: "<<padre->izquierda->FE<<endl;
                //cout<<" Padre: "<<padre->texto<<endl;
                if((PadreAB->FE<-1) && (sHijo->FE<0)){
                    //cout<<"Rotacion simple a la derecha"<<endl;
                    //cout<<" Padre: "<<padre->texto<<" Hijo: "<<padre->izquierda->texto<<endl;
                    rotacionSimpleDerecha(padre);
                    recorrer(raiz);
                
                }else if((PadreAB->FE<-1) && (sHijo->FE>0)){
                    //cout<<"Rotacion doble a la izquierda "<<endl;
                    //cout<<" Padre: "<<padre->texto<<" Hijo: "<<padre->izquierda->texto<<endl;
                    rotacionDobleIzquierda(padre);
                        //p->padre->derecha = padre;
                    recorrer(raiz);

                }
            }
        }
    }
}




void Arbol::recorrer(Nodo* padre){
    //
    if(padre!=NULL){
        //cout<<"El nodo padre "<<padre->texto<<endl;
        if(padre->izquierda==NULL){
            //padre->alturaDerecha = 0;
            //cout<<"El nodo 0000000 iiiiiii: "<<padre->texto<<endl;
            padre->alturaIzquierda = 0;
        }else{
            //cout<<"Entri en: ZIIIZIZIIZIZ"<<endl;
            recorrer(padre->izquierda);
            verificarAlturaIzquierda(padre);
        }
        //cout<<"El nodo RAIZ ddddd"<<endl;
        if(padre->derecha==NULL){
            //cout<<"El nodo 0000000 dddddddd"<<endl;
            padre->alturaDerecha = 0;
            //padre->alturaIzquierda = 0;
        }else{
            //cout<<"Entri en: DDDDDDDDDDDDD: "<<padre->texto<<endl;
            recorrer(padre->derecha);
            //cout<<"salio en: DDDDDDDDDDDDD: "<<padre->texto<<endl;
            verificarAlturaDerecha(padre);
        }
        //cout<<"El nodo"<<padre->peso<<"---- tiene una altura: izq: "<<padre->alturaIzquierda<<"  der: "<<padre->alturaDerecha<<endl;
        if(padre!=NULL){
            //cout<<"El nodo fefefefefefe "<<endl;
            padre->FE = padre->alturaDerecha-padre->alturaIzquierda;
        }else{
            //cout<<"El nodo"<<endl;
        }
    }else{
        //cout<<"El nodo  NULL"<<endl;
    }
    //cout<<"TERMIKNA El nodo"<<endl;
    //cout<<"El nodo"<<padre->peso<<"---- tiene una altura: izq: "<<padre->alturaIzquierda<<"  der: "<<padre->alturaDerecha<<"    pOR LO TANTO FE: "<<padre->FE<<endl;
}


Arbol::~Arbol() {
}

