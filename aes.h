#ifndef CRYPTOGRAPHYSCRIPTS_AES_H
#define CRYPTOGRAPHYSCRIPTS_AES_H


#include "cipher.h"
#include "cipher_inverse.h"
#include "key.h"
#include "plaintext.h"
#include "state.h"
#include "s_box_inverse.h"
#include "s_box.h"

class AES {
public:
    static const int Nb = 4;
    static const int Nr = 10;
    static const int Nk = 4;
    Utility* utility;
    State* state;
    Cipher* cipher;
    CipherInverse* cipher_inverse;
    SBox* s_box;
    SBoxInverse* s_box_inverse;
    uint8_t key_schedule[Nb][Nr+1];

    AES();
    void encrypt(Plaintext* plaintext, Key* key);
    void generateKeySchedule(Key* key);
    uint8_t* subWord(uint8_t word[4]);
    uint8_t* rotWord(uint8_t word[4]);
};


#endif //CRYPTOGRAPHYSCRIPTS_AES_H