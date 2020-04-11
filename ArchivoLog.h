/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArchivoLog.h
 * Author: yefer
 *
 * Created on 11 de abril de 2020, 03:33 PM
 */

#ifndef ARCHIVOLOG_H
#define ARCHIVOLOG_H
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

class ArchivoLog {
public:
    ArchivoLog();
    ArchivoLog(const ArchivoLog& orig);
    virtual ~ArchivoLog();
private:

};

#endif /* ARCHIVOLOG_H */

