#ifndef CRYPTOGRAPHYSCRIPTS_S_BOX_H
#define CRYPTOGRAPHYSCRIPTS_S_BOX_H


#include <fstream>
#include <iostream>

using namespace std;

class SBox {
public:
    uint8_t substitutionTable[15][15];
    void initializeSBox();
};

#endif //CRYPTOGRAPHYSCRIPTS_S_BOX_H
