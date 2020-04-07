

#include "Columna.h"

Columna::Columna() {
}

Columna::Columna(string titulo, int tipo){
    this->titulo = titulo;
    this->tipo = tipo;
}

int Columna::GetTipo(){
    return tipo;
}

void Columna::SetTipo(int tipo) {
    this->tipo = tipo;
}

string Columna::GetTipoTexto(){
    return tipoTexto;
}

void Columna::SetTipoTexto(string tipoTexto) {
    this->tipoTexto = tipoTexto;
}

string Columna::GetTitulo(){
    return titulo;
}

void Columna::SetTitulo(string titulo) {
    this->titulo = titulo;
}


Columna::~Columna() {
}

