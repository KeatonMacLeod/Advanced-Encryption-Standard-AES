#ifndef CRYPTOGRAPHYSCRIPTS_CIPHER_INVERSE_H
#define CRYPTOGRAPHYSCRIPTS_CIPHER_INVERSE_H


#include "state.h"
#include "utility.h"
#include "s_box_inverse.h"

class CipherInverse {
public:
    Utility* utility;
    CipherInverse();
    void addRoundKey(State* state, uint8_t key_schedule[44][4], int key_schedule_offset);
    void invShiftRows(State* state);
    void invSubBytes(State* state, SBoxInverse* s_box_inverse);
    void invMixColumns();

};


#endif //CRYPTOGRAPHYSCRIPTS_CIPHER_INVERSE_H
