

#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std;

class Hash {
public:
    Hash();
    int funcionHash(string &texto);
    int encontrarPeso(string);
    virtual ~Hash();
private:
    
};

#endif /* HASH_H */

