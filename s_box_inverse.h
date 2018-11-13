#ifndef CRYPTOGRAPHYSCRIPTS_S_BOX_INVERSE_H
#define CRYPTOGRAPHYSCRIPTS_S_BOX_INVERSE_H

#include <fstream>
#include <iostream>

using namespace std;

class SBoxInverse {
public:
    uint8_t substitutionTable[15][15];
    void initializeSBox();
};

#endif //CRYPTOGRAPHYSCRIPTS_S_BOX_INVERSE_H
