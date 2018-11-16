#ifndef CRYPTOGRAPHYSCRIPTS_S_BOX_H
#define CRYPTOGRAPHYSCRIPTS_S_BOX_H

#include <fstream>
#include <iostream>
#include "utility.h"

using namespace std;

class SBox {
public:
    Utility* utility;
    uint8_t substitutionTable[16][16];
    SBox();
    void initializeSBox();
};

#endif //CRYPTOGRAPHYSCRIPTS_S_BOX_H
