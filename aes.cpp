#include <cmath>
#include "aes.h"

AES::AES() {
    //Initialize display functionality
    display = new Display();

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

//Figure 5 in Section 5.1
void AES::encrypt(Plaintext* plaintext, Key* key) {
    //Read the plaintext into the State array
    state->readPlaintextIntoState(plaintext);

    //Stored in AES' key_schedule variable
    generateKeySchedule(key);

    //Display results to console
    display->displayKeySchedule(key_schedule);
    display->displayEncryptionProcess();
    display->displayPlaintext(plaintext);

    //Initial AddRoundKey
    cipher->addRoundKey(state, key_schedule, 0);

    display->displayEncryptionRound(state, 1);

    //Begin the encryption rounds
    for (int round = 1; round < Nr; round++) {
        cipher->subBytes(state, s_box);
        cipher->shiftRows(state);
        cipher->mixColumns(state);
        cipher->addRoundKey(state, key_schedule, round*Nb);
        display->displayEncryptionRound(state, round+1);
    }

    cipher->subBytes(state, s_box);
    cipher->shiftRows(state);
    cipher->addRoundKey(state, key_schedule, 40);
    display->displayEncryptionRound(state, 11);
}

//Figure 12 in Section 5.3
void AES::decrypt() {

    //Display results to console
    display->displayDecryptionProcess();
    display->displayDecryptionRound(state, 10);

    //Initial AddRoundKey
    cipher_inverse ->addRoundKey(state, key_schedule, 40);

    for (int round = Nr-1; round > 0; round--) {
        cipher_inverse->invShiftRows(state);
        cipher_inverse->invSubBytes(state, s_box_inverse);
        display->displayDecryptionRound(state, round);
        cipher_inverse->addRoundKey(state, key_schedule, round*Nb);
        cipher_inverse->invMixColumns(state);
    }

    cipher_inverse->invShiftRows(state);
    cipher_inverse->invSubBytes(state, s_box_inverse);
    display->displayDecryptionRound(state, 0);
    cipher_inverse->addRoundKey(state, key_schedule, 0);
    display->displayDecryptionRound(state, -1);
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

        // Copy key_schedule[i-1] to a temporary array so we can make modifications without
        // changing the original data
        uint8_t temp_array[4];
        uint8_t* temp_ptr;
        copy(begin(key_schedule[i-1]), end(key_schedule[i-1]), begin(temp_array));

        if (i % Nk == 0) {

            //Perform the RotWord() and SubWord() functions
            temp_ptr = subWord(rotWord(temp_array));

            // Perform XOR with round constant array
            for (int j=0; j<4; j++) {
                temp_ptr[j] = temp_ptr[j] ^ Rcon[j];
            }

            // Perform Galois multiplication to increment round constant array
            uint8_t galois_multipled_byte = utility->galoisMultiply(Rcon[0], 0x02);
            Rcon[0] = galois_multipled_byte;
        }

        //Set the respective key based off the computations above
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

/*************************
 * DISPLAY FUNCTIONALITY *
 *************************/



