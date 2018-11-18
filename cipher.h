#ifndef CRYPTOGRAPHYSCRIPTS_CIPHER_H
#define CRYPTOGRAPHYSCRIPTS_CIPHER_H


#include "state.h"

class Cipher {
public:
    void subBytes();
    void shiftRows();
    void mixColumns();
    void addRoundKey(State* state, uint8_t key_schedule[44][4], int start, int end);
};


#endif //CRYPTOGRAPHYSCRIPTS_CIPHER_H
