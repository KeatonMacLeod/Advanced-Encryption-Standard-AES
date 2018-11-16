#include "aes.h"

AES::AES() {
    state = new State();
    cipher = new Cipher();
    cipher_inverse = new CipherInverse();
}

void AES::encrypt(Plaintext* plaintext, Key* key) {
    state->readPlaintextIntoState(plaintext);
    int x = 2+2;
}