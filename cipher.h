#ifndef CRYPTOGRAPHYSCRIPTS_CIPHER_H
#define CRYPTOGRAPHYSCRIPTS_CIPHER_H


#include "state.h"
#include "s_box.h"

class Cipher {
public:
    Utility* utility;
    Cipher();
    void addRoundKey(State* state, uint8_t key_schedule[44][4], int key_schedule_offset);
    void subBytes(State* state, SBox* s_box);
    void shiftRows(State* state);
    void mixColumns(State* state);

};


#endif //CRYPTOGRAPHYSCRIPTS_CIPHER_H
