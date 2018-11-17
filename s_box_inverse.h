#ifndef CRYPTOGRAPHYSCRIPTS_S_BOX_INVERSE_H
#define CRYPTOGRAPHYSCRIPTS_S_BOX_INVERSE_H

#include <fstream>
#include <iostream>
#include "utility.h"

using namespace std;

class SBoxInverse {
public:
    Utility* utility;
    uint8_t substitutionTable[16][16];
    SBoxInverse();
    void initializeSBox();
    uint8_t lookup(uint8_t byte);
};

#endif //CRYPTOGRAPHYSCRIPTS_S_BOX_INVERSE_H
