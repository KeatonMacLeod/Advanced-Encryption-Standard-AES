#ifndef CRYPTOGRAPHYSCRIPTS_CIPHER_H
#define CRYPTOGRAPHYSCRIPTS_CIPHER_H


#include "state.h"
#include "s_box.h"

class Cipher {
public:
    void addRoundKey(State* state, uint8_t key_schedule[44][4], int start, int end);
    void subBytes(State* state, SBox* s_box);
    void shiftRows();
    void mixColumns();

};


#endif //CRYPTOGRAPHYSCRIPTS_CIPHER_H
