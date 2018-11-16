#ifndef CRYPTOGRAPHYSCRIPTS_CIPHER_H
#define CRYPTOGRAPHYSCRIPTS_CIPHER_H


class Cipher {
public:
    void subBytes();
    void shiftRows();
    void mixColumns();
    void addRoundKey();
};


#endif //CRYPTOGRAPHYSCRIPTS_CIPHER_H
