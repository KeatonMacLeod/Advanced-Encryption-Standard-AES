#include "cipher.h"

//CONFIRMED WORKING PROPERLY
void Cipher::addRoundKey(State* state, uint8_t key_schedule[44][4], int start, int end) {
    for (int i=start; i<=end; i++) {
        for (int j=0; j<4; j++) {
            state->state[j][i] = state->state[j][i] ^ key_schedule[i][j];
        }
    }
}

void Cipher::subBytes(State* state, SBox* s_box) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            state->state[j][i] = s_box->lookup(state->state[j][i]);
        }
    }
}

void Cipher::shiftRows() {

}

void Cipher::mixColumns() {

}