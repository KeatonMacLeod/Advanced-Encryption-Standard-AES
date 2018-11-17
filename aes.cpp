#include "aes.h"

AES::AES() {
    //Initialize state, cipher, and inverse cipher
    state = new State();
    cipher = new Cipher();
    cipher_inverse = new CipherInverse();

    //Initialize regular S-Box
    s_box = new SBox();
    s_box->initializeSBox();

    //Initialize inverse S-Box
    s_box_inverse = new SBoxInverse();
    s_box_inverse->initializeSBox();
}

void AES::encrypt(Plaintext* plaintext, Key* key) {

    //Read the plaintext into the State array
    state->readPlaintextIntoState(plaintext);

    generateKeySchedule(key);
}

//Figure 11 in Section 5.2 Key Expansion
void AES::generateKeySchedule(Key *key) {

    //Clear the key_schedule
    for(int row=0; row<Nb; row++) {
        for (int col=0; col<Nr+1; col++) {
            key_schedule[row][col] = 0x00;
        }
    }

    //Create words to pass into sub-words denoted w[i] in the document
    uint8_t w[Nk][4];

    for (int i = 0; i < Nk; i++) {
        w[i][0] = key->key_bytes[4*i];
        w[i][1] = key->key_bytes[4*i+1];
        w[i][2] = key->key_bytes[4*i+2];
        w[i][3] = key->key_bytes[4*i+3];
    }

    for (int i = Nk; i < Nb * (Nr + 1); i++) {
        uint8_t* temp = w[i-1];
        if (i % Nk == 0)
            temp = subWord(rotWord(temp)); //XOR Rcon[i/Nk]
    }
}

// Takes in a 4-byte word an applies the S-box to
// each of the 4-bytes to produce an output word
uint8_t* AES::subWord(uint8_t word[4]) {
    for (int i=0; i<4; i++) {
        word[i] = s_box->lookup(word[i]);
    }
    return word;
}

// Takes a word as input and performs a cyclic permutation
// returning [a0,a1,a2,a3] as [a1,a2,a3,a0]
uint8_t* AES::rotWord(uint8_t word[4]) {
    uint8_t temp = word[0];
    for(int i=0; i<3; i++) {
        word[i] = word[i+1];
    }
    word[3] = temp;
    return word;
}