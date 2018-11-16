#ifndef CRYPTOGRAPHYSCRIPTS_CIPHER_INVERSE_H
#define CRYPTOGRAPHYSCRIPTS_CIPHER_INVERSE_H


class CipherInverse {
public:
    void invSubBytes();
    void invShiftRows();
    void invMixColumns();
    void addRoundKey();
};


#endif //CRYPTOGRAPHYSCRIPTS_CIPHER_INVERSE_H
