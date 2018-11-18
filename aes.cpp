#include <cmath>
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

//CONFIRMED WORKING PROPERLY
//Figure 11 in Section 5.2 Key Expansion
void AES::generateKeySchedule(Key *key) {

    //Clear the key_schedule
    for(int row=0; row<Nb*(Nr+1); row++) {
        for (int col=0; col<Nk; col++) {
            key_schedule[row][col] = 0x00;
        }
    }

    for (int i = 0; i < Nk; i++) {
        key_schedule[i][0] = key->key_bytes[4*i];
        key_schedule[i][1] = key->key_bytes[4*i+1];
        key_schedule[i][2] = key->key_bytes[4*i+2];
        key_schedule[i][3] = key->key_bytes[4*i+3];
    }

    uint8_t Rcon[4];
    Rcon[0] = 0x01; // <-- Initialized to 0x01 to make code simpler (since first round uses 01 in first byte)
    Rcon[1] = 0x00; //    still same results as 0x02 due to order of operations below
    Rcon[2] = 0x00;
    Rcon[3] = 0x00;

    for (int i = Nk; i < (Nb * (Nr + 1)); i++) {
        uint8_t temp_array[4];
        uint8_t* temp_ptr;
        copy(begin(key_schedule[i-1]), end(key_schedule[i-1]), begin(temp_array));

        if (i % Nk == 0) {
            temp_ptr = subWord(rotWord(temp_array));

            // Perform XOR with round constant array
            for (int j=0; j<4; j++) {
                temp_ptr[j] = temp_ptr[j] ^ Rcon[j];
            }

            // Perform Galois multiplication to increment round constant array
            uint8_t galois_multipled_byte = utility->galoisMultiply(Rcon[0]);
            Rcon[0] = galois_multipled_byte;
        }

        key_schedule[i][0] = key_schedule[i-Nk][0] ^ temp_ptr[0];
        key_schedule[i][1] = key_schedule[i-Nk][1] ^ temp_ptr[1];
        key_schedule[i][2] = key_schedule[i-Nk][2] ^ temp_ptr[2];
        key_schedule[i][3] = key_schedule[i-Nk][3] ^ temp_ptr[3];
    }
}

//CONFIRMED WORKING PROPERLY
// Takes in a 4-byte word an applies the S-box to
// each of the 4-bytes to produce an output word
uint8_t* AES::subWord(uint8_t word[4]) {
    for (int i=0; i<4; i++) {
        word[i] = s_box->lookup(word[i]);
    }
    return word;
}

//CONFIRMED WORKING PROPERLY
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