

#include "Nodo.h"

Nodo::Nodo() {
}

Nodo::Nodo(string text, int peso, string col) {
    texto = text;
    this->peso = peso;
    columna = col;
    izquierda = NULL;
    derecha = NULL;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

