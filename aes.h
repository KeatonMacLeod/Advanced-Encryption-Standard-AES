#ifndef CRYPTOGRAPHYSCRIPTS_AES_H
#define CRYPTOGRAPHYSCRIPTS_AES_H


#include "cipher.h"
#include "cipher_inverse.h"
#include "key.h"
#include "plaintext.h"
#include "state.h"

class AES {
public:
    State* state;
    Cipher* cipher;
    CipherInverse* cipher_inverse;
    AES();
    void encrypt(Plaintext* plaintext, Key* key);
};


#endif //CRYPTOGRAPHYSCRIPTS_AES_H